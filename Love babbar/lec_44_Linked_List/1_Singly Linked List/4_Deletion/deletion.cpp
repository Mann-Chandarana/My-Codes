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

    // ~Node()
    // {
    //     int val = this->data;
    //     if (this->next != NULL)
    //     {
    //         delete next;
    //         this->next = NULL;
    //     }
    //     cout << "Destructor called with value " << val << endl;
    // }
    // If we want to use the destrucotr, make sure to point the object to a NULL pointer
    // del->next = NULL; // Requried if we want to use given destructor.
    // delete del;
};

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        tail = head;
        return;
    }

    Node *temp = new Node(val);

    tail->next = temp;
    tail = temp;

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

// Delete at position
void deleteAtK(Node *&head, Node *&tail, int k)
{
    if (head == NULL)
        return;

    Node *temp = head;
    if (k == 1)
    {
        head = head->next;
        delete temp;
        return;
    }

    int cnt = 1;

    while (cnt < k - 1)
    {
        // If k is larger than the total length of the linked list
        if (temp->next->next == NULL)
        {
            break;
        }
        cnt++;
        temp = temp->next;
    }

    if (temp->next->next == NULL)
    {
        tail = temp;
        tail->next = NULL;
        temp = temp->next;
        delete temp;
    }
    else
    {
        Node *del = temp->next;
        temp->next = temp->next->next;

        delete del;
    }
}

void deleteValue(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
        return;

    if (head->data == val)
    {
        if (head->next == NULL)
        {
            Node *del = head;
            head = head->next;
            tail = head;
            delete del;
        }
        else
        {
            Node *del = head;
            head = head->next;
            delete del;
        }
        return;
    }

    Node *temp = head;
    while (temp->next != NULL and temp->next->data != val)
    {
        if ((temp->next->next == NULL) and (temp->next->data == val)) // At tail
        {
            tail = temp;
            temp = temp->next;
            tail->next = NULL;

            delete temp;
            return;
        }

        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        Node *del = temp->next;
        temp->next = temp->next->next;

        delete del;
        return;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = head;

    insertAtTail(head, tail, 110);
    insertAtTail(head, tail, 120);
    insertAtTail(head, tail, 130);
    insertAtTail(head, tail, 140);
    insertAtTail(head, tail, 150);
    insertAtTail(head, tail, 160);
    insertAtTail(head, tail, 170);
    insertAtTail(head, tail, 180);
    insertAtTail(head, tail, 190);

    cout << "Before deletion:\n";
    printLinkedList(head);

    // cout << "Insert the position: ";
    // int k;
    // cin >> k;
    // deleteAtK(head, tail, k);

    cout << "Insert value you want to delete: ";
    int val;
    cin >> val;
    deleteValue(head, tail, val);

    cout << "After deletion:\n";
    printLinkedList(head);

    return 0;
}