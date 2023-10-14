#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
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

void evenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
}

int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        insertAtTail(head, arr[i]);
    }
    displayLinkedList(head);
    evenAfterOdd(head);
    displayLinkedList(head);

    return 0;
}