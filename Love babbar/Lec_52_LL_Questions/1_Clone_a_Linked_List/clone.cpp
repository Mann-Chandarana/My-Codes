#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}

void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *makeClone(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *newHead = new Node(head->data);
    Node *temp = newHead;
    head = head->next;

    while (head)
    {
        temp->next = new Node(head->data);
        temp = temp->next;
        head = head->next;
    }

    return newHead;
}

int main()
{
    Node *head1 = NULL;
    int n = 10;
    // cin >> n;

    for (int i = 1; i <= n; i++)
        insertAtTail(head1, i);
    Node *head2 = makeClone(head1);
    printLL(head1);
    printLL(head2);

    head2->next->data = 999999;
    head2->next->next->next->next = NULL;
    printLL(head1);
    printLL(head2);

    return 0;
}