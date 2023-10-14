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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
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
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void displayLinkedList(node *&head)
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "NULL";
    }
    else
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void deleteAtHead(node *&head)
{
    node *toDelete;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    toDelete = head;
    head = temp->next;
    delete toDelete;
    return;
}

void deletion(node *&head, int pos)
{
    node *toDelete = head;
    int len = getLength(head);
    int count = 1; // To get to the left element of the position in the LL.
    node *temp = head;
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    else if (pos > 0 && pos <= len)
    {
        while (count != pos - 1)
        {
            count++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete toDelete;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    node *head = NULL;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        insertAtTail(head, arr[i]);
    }

    displayLinkedList(head);
    deletion(head, 1);
    displayLinkedList(head);
    insertAtHead(head, 1);
    // deleteAtHead(head);
    displayLinkedList(head);

    return 0;
}