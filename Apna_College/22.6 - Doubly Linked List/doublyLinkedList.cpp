#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL) // If head is null then we cannot access its previous pointer.
    {
        head->prev = n;
    }

    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

// void deletion(node *&head, int val)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     node *toDelete;
//     if (head->data == val) // If val is at head.
//     {
//         toDelete = head;
//         head->next->prev = NULL;
//         head = head->next;
//     }
//     else{

//     }
//     delete toDelete;
// }

void deletionAtPosition(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) // If position is greater than the size of the Linked List.
    {
        return;
    }
    if (temp->prev == NULL) // Head
    {
        temp->next->prev = NULL;
        head = temp->next;
    }
    else if (temp->next == NULL) // Tail
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void displayLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // displayLinkedList(head);
    insertAtHead(head, 1);
    displayLinkedList(head);

    // deletionAtPosition(head, 1); // Here 1 is position (Not index).
    deletionAtPosition(head, 6);
    displayLinkedList(head);

    return 0;
}