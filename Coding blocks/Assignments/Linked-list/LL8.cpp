//////// Linked list -K append

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

Node *Append_Kth(Node *head, int k, int n)
{
    if (k == n)
    {
        return head;
    }
    else if (k > n)
    {
        k = k % n;
    }

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *fast = head;
    Node *slow = head;
    int count = 0;

    while (fast != NULL && count < k)
    {
        fast = fast->next;
        count++;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *newHead = slow->next;
    slow->next = NULL;
    fast->next = head;
    return newHead;
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
    int var = n;
    Node *head = NULL;
    while (var--)
    {
        cin >> ele;
        insert_at_last(head, ele);
    }
    cin >> k;
    Node *newHead = Append_Kth(head, k, n);
    print_list(newHead);

    return 0;
}