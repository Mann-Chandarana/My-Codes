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
            temp = temp->next;

        temp->next = new Node(val);
    }
}

void printLL(Node *&head)
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

void reverseLLIterative(Node *&head)
{
    if (head == NULL)
        return;

    Node *prevPtr = NULL;
    Node *currPtr = head;
    Node *nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }

    head = prevPtr;
}

Node *reverseLLRec(Node *&head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *newHead = reverseLLRec(head->next);
    head->next->next = head;
    head->next = NULL; // This is for the head node of the original linked list.

    return newHead;
}

void reverseLLRec1(Node *&head,Node*curr,Node*prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverseLLRec1(head, forward, curr);
    curr->next = prev;
}

int main()
{

    Node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    insertAtTail(head, 80);

    printLL(head);

    reverseLLIterative(head);
    printLL(head);

    Node *newHead = reverseLLRec(head);
    printLL(newHead);

    cout << "\n\nMain end...\n\n";
    return 0;
}