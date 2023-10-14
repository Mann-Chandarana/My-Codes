#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
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
    if (tail == NULL)
    {
        insertAtHead(head, val);
        tail = head;
        return;
    }

    Node *temp = new Node(val);
    tail->next = temp;
    tail = tail->next;

    temp = temp->next;
    delete temp;
}

void insertAtKPos(Node *&head, Node *&tail, int k, int val)
{
    int cnt = 1;
    Node *temp = head;

    if (k <= 1)
    {
        insertAtHead(head, val);
        return;
    }

    if (head == NULL)
    {
        insertAtTail(head, tail, val);
        return;
    }

    while (cnt < k - 1)
    {
        if (temp == NULL)
        {
            insertAtTail(head, tail, val);
            return;
        }
        cnt++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        insertAtTail(head, tail, val);
        return;
    }
    else
    {
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
    Node *tail = head;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);

    printLinkedList(head);

    int k = 1;
    insertAtKPos(head, tail, k, 0);
    printLinkedList(head);

    return 0;
}