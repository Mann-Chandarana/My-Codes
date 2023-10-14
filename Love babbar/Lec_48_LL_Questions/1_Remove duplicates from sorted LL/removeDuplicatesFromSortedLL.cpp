#include <bits/stdc++.h>
using namespace std;

// Look for remove in sorted and unsorted in codestudio....

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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *uniqueSortedList(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *start = head;
    Node *temp = head->next;

    while (temp != NULL)
    {
        while (temp != NULL and temp->data == start->data)
        {
            temp = temp->next;
        }
        start->next = temp;
        start = temp;
        if (temp != NULL)
            temp = temp->next;
    }

    return head;
}

int main()
{
    Node *head = NULL;
    // // Sorted in descending order
    // insertAtTail(head, 5);
    // insertAtTail(head, 5);
    // insertAtTail(head, 4);
    // insertAtTail(head, 3);
    // insertAtTail(head, 3);
    // insertAtTail(head, 3);
    // insertAtTail(head, 2);
    // insertAtTail(head, 1);
    // insertAtTail(head, 1);

    // Sorted in ascending order
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 6);
    insertAtTail(head, 6);
    insertAtTail(head, 6);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    // insertAtTail(head, 10);

    printLL(head);

    uniqueSortedList(head);

    printLL(head);

    return 0;
}