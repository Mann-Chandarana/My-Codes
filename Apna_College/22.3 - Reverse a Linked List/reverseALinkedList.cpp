#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void displayLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Printing a linked list in reverse order. List will stay the same as before.
void printReverse(node *head)
{
    node *temp = head;
    if (temp == NULL)
        return;
    else
        printReverse(temp->next);
    cout << temp->data << " ";
}

// Reversing the Linked List. Tail will become head and head will become tail.
// 1. Iterative Method
node *reverseUsingIterator(node *&head)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr; // New head.
}
// 2. Recursive Method
node *reverseUsingRecursion(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newHead = reverseUsingRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    displayLinkedList(head);
    // printReverse(head);
    // node *newHead = reverseUsingIterator(head);
    node *newHead = reverseUsingRecursion(head);
    displayLinkedList(newHead);

    // reverseUsingRecursion(head);

    return 0;
}