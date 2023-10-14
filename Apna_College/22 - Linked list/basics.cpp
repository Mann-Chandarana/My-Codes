#include <iostream>
using namespace std;

class node
{
    // If you want to make data and next variable private, Make all the functions friend functions of this class.
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

void insertAtTail(node *&head, int val) // Taken head pointer by reference so that we can modify it.
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void displayLinkedList(node *head) // taken head pointer by reference value because no need to modify it.
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    /*  We can simply traverse using head pointer also.

        while(head != NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }   
    */
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    // node n1(1);
    // node *head = &n1;

    node *head = NULL;     // Making an empty linked list.
    insertAtTail(head, 2); // Adding a value at tail.
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 89);
    displayLinkedList(head);

    insertAtHead(head, 0);
    displayLinkedList(head);

    cout << search(head, 89) << endl;
    cout << search(head, -10) << endl;

    return 0;
}
