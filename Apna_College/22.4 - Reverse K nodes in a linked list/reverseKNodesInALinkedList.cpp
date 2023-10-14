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

node *reverseKNodesUsingRecursion(node *&head, int k)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;
    int count = 0;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while ((currPtr != NULL) && (count < k))
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if (currPtr != NULL)
    {
        head->next = reverseKNodesUsingRecursion(currPtr, k);
    }

    return prevPtr;
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

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    displayLinkedList(head);
    int k = 3;
    // int k = 4;
    node *newHead = reverseKNodesUsingRecursion(head, k);
    displayLinkedList(newHead);

    return 0;
}