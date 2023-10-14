#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    temp = temp->prev;
    delete temp;
}

void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
        insertAtHead(head, val);
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        Node *newNode = new Node(val);

        temp->next = newNode;
        newNode->prev = temp;

        newNode = newNode->next;
        temp = temp->next->next;

        delete newNode;
        delete temp;
    }
}

void insertAtK(Node *&head, int k, int val)
{
    if (k == 1)
    {
        insertAtHead(head, val);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < k - 1)
    {
        if (temp->next == NULL) // If k become greater than the length of linked list.
            break;

        temp = temp->next;
        cnt++;
    }

    Node *newNode = new Node(val);
    if (temp->next == NULL) // Last node
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void printDoublyLL(Node *&head)
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

/////// Important
void deleteLL(Node *&head)
{
    if (head == NULL)
        return;

    deleteLL(head->next);

    head->next = NULL;
    head->prev = NULL;
    delete head;
}

int main()
{

    Node *head = new Node(100);
    insertAtTail(head, 110);
    insertAtTail(head, 120);
    insertAtTail(head, 130);
    insertAtTail(head, 140);
    insertAtTail(head, 150);
    insertAtTail(head, 160);

    insertAtHead(head, 170);

    insertAtTail(head, 180);

    printDoublyLL(head);

    Node *temp;
    temp = head->next->next->next;

    cout << "Value of temp: " << temp->data << endl;
    cout << "Value of previous node of temp: " << temp->prev->data << endl;
    cout << "Value of next node of temp: " << temp->next->data << endl;

    // cout << head->next->prev->data + 1000 << endl;

    // printDoublyLL(head);
    // deleteLL(head);
    // printDoublyLL(head);

    cout << "\n";

    printDoublyLL(head);
    int k, val;
    cout << "Enter index: ";
    cin >> k;
    cout << "Enter value: ";
    cin >> val;
    insertAtK(head, k, val);
    printDoublyLL(head);

    cout << "Main end..." << endl;
    return 0;
}