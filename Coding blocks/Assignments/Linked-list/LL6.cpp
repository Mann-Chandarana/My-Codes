////////// isPalindrome

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node(){};
    ~Node()
    {
        if (next != NULL)
        {
            next == NULL;
        }
    }
};

void print_list(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse_List(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    Node *newHead = reverse_List(Head->next);
    Head->next->next = Head;
    Head->next = NULL;

    return newHead;
}

Node *get_Middle(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    Node *fast = Head;
    Node *slow = Head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }
    return slow;
}

bool is_Palindrome(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return 1;
    }

    Node *middle = get_Middle(Head);
    Node *temp = middle->next;

    middle->next = reverse_List(temp);

    Node *Head1 = Head;
    Node *Head2 = middle->next;

    while (Head2 != NULL)
    {
        if (Head2->data != Head1->data)
        {
            return 0;
        }
        Head1 = Head1->next;
        Head2 = Head2->next;
    }
    temp = middle->next;
    middle->next = reverse_List(temp);
    return 1;
}

void insert_at_last(Node *&Head, int data)
{
    Node *temp = new Node(data);
    if (Head == NULL)
    {
        Head = temp;
        Head->next = NULL;
        return;
    }
    Node *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

int main()
{
    int n, ele, k;
    cin >> n;
    Node *head = NULL;
    while (n--)
    {
        cin >> ele;
        insert_at_last(head, ele);
    }
    if (is_Palindrome(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}