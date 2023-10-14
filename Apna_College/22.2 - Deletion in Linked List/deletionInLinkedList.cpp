#include <iostream>
using namespace std;

// Bried explanation of deletion in a linked list.
/*
    1 -> 2 -> 3 -> 4 -> NULL
    We want to delete 3 (nth node).
    In the next pointer of node with value 2 which is the (n-1)th node,
    give the address of node with value 4 (n+1)th node.
    1  -> 2 -> 4 -> NULL
            -> 3    // Rremoved from the Linked List. 
*/

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
    node() {}
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

// Create delete at head
void deleteAtHead(node *&head)
{
    node *toDelete = head;
    if (head == NULL)
    {
        return;
    }
    else
        head = head->next;
    delete toDelete;
}

// Create delete at tail
void deleteAtTail(node *&head)
{
    node *temp = head;
    node *toDelete;
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        toDelete = head;
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = NULL;
        delete toDelete;
    }
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    node *toDelete; // Store the deleted node. So that we can delete that value from the memory.

    if (head->data == val) // If val is at first node of LL.
    {
        toDelete = head;
        head = head->next;
    }
    else
    {
        while ((temp->next->data != val) && (temp->next->next != NULL)) // Traversing to the (n-1)th node, where nth node has the value we want to delete.
        // The other condition in && is to check whether there exist no such number we want find.
        {
            temp = temp->next;
        }

        if ((temp->next->next == NULL) && (temp->next->data != val)) // If val is not there in LL.
        {
            return;
        }
        else if ((temp->next->next == NULL) && (temp->next->data == val)) // If value is at the last position in LL.
        {
            toDelete = temp->next;
            temp->next = NULL;
        }
        else
        {
            toDelete = temp->next;
            temp->next = temp->next->next;
        }
    }
    delete toDelete; // Delete the value from the memory.
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
    node n(1);
    node *head = &n;
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    displayLinkedList(head);

    deletion(head, 1); // Delete a value which is there in LL.
    deletion(head, 15); // Try to delete a value which is not there in LL.
    deleteAtHead(head); // Delete the value which is at head pointer.
    deleteAtTail(head); //  Delete the value which is at tail pointer.

    displayLinkedList(head);
    cout << "Done" << endl;

    return 0;
}