#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);

    if (tail == NULL)
    {
        insertAtHead(head, val);
        tail = head;
        return;
    }

    tail->next = temp;
    tail = tail->next;

    temp = temp->next;
    delete temp;
}

void printLinkedList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    delete temp;
}

int main()
{

    Node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);

    printLinkedList(head);

    cout << endl;

    Node *head1 = NULL;
    Node *tail1 = head1;
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 2);
    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);

    printLinkedList(head1);

    return 0;
}