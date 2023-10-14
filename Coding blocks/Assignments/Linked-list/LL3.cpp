////////// Even after odd

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

void evenodd(Node *&head)
{
    Node *evenstart = NULL;
    Node *evenend = NULL;
    Node *oddend = NULL;
    Node *oddstart = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        int val = curr->data;
        if (val % 2 == 0)
        {
            if (evenstart == NULL)
            {
                evenstart = curr;
                evenend = evenstart;
            }
            else
            {
                evenend->next = curr;
                evenend = evenend->next;
            }
        }
        else
        {
            if (oddstart == NULL)
            {
                oddstart = curr;
                oddend = oddstart;
            }
            else
            {
                oddend->next = curr;
                oddend = oddend->next;
            }
        }
        curr = curr->next;
    }
    if (oddstart == NULL || evenstart == NULL)
    {

        return;
    }

    oddend->next = evenstart;
    evenend->next = NULL;
    head = oddstart;
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
    evenodd(head);
    print_list(head);

    return 0;
}