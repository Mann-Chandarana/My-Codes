////////// Sum of two list

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

Node *add_two_list(Node *first, Node *second)
{
    int carry = 0;

    Node *ans = NULL;
    first = reverse_List(first);
    second = reverse_List(second);

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = val1 + val2 + carry;

        int digit = sum % 10;

        insert_at_last(ans, digit);

        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    ans = reverse_List(ans);
    return ans;
}

int main()
{
    int n1, n2, ele, k;
    cin >> n1>>n2;
    Node *head1 = NULL;
    Node *head2 = NULL;
    while (n1--)
    {
        cin >> ele;
        insert_at_last(head1, ele);
    }
    while (n2--)
    {
        cin >> ele;
        insert_at_last(head2, ele);
    }
    Node *head3 = add_two_list(head1, head2);

    print_list(head3);

    return 0;
}