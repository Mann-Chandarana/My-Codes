#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int n)
    {
        this->data = n;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *node = new Node(val);
    // if (head == NULL)
    // {
    //     head = node;
    // }
    // else
    // {
    //     node->next = head;
    //     head = node;
    // }
    node->next = head;
    head = node;
}

void insertAtTail(Node *&head, int val)
{
    Node *node = new Node(val);
    if (head == NULL) // Empty LL
    {
        insertAtHead(head, val);
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;

        // At this point temp is at the second last element of the linked list.
        // We move temp 2 times forward, And now temp is pointing to NULL.
        // Now we can delet temp from the heap memory.
        temp = temp->next;
        temp = temp->next;
        delete temp;
    }
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // We can also use this, but in this case we have to pass the node by value and not by reference.
    // while (head != NULL)
    // {
    //     cout << head->data << " ";
    //     head = head->next;
    // }

    delete temp;
    cout << endl;
}

int main()
{
    /*
    Node *node = new Node(5);
    Node *n1 = new Node(7);
    node->next = n1;
    Node *n2 = new Node(1);
    n1->next = n2;
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    */

    // Node *head = new Node(1);
    Node *head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 6);
    insertAtTail(head, 9);
    insertAtHead(head, -1);
    insertAtTail(head, 19);
    insertAtTail(head, 4);
    insertAtHead(head, -8);
    insertAtTail(head, 100);

    printLinkedList(head);
    cout << head->data << endl;

    return 0;
}