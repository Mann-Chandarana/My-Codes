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
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// void func(node *head)
// void func(node *&head)
// {
//     head->data = 333; // Value at head will become 333 in both the cases.
// }

int getLength(node *head)
{
    node *temp = head;
    int len = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node *kAppend(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;

    int len = getLength(head);
    int count = 0;
    k = k % len;
    if (k == 0)
        return head;
    while (tail != NULL)
    {
        count++;
        if (count == (len - k))
        {
            newTail = tail;
        }
        if (count == (len - k + 1))
        {
            newHead = tail;
        }
        if (tail->next == NULL)
            break;
        tail = tail->next;
    }
    tail->next = head;
    newTail->next = NULL;

    return newHead;
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
    int i,size,k;
    cout << "Enter the size fo the linked list: ";
    cin >> size;
    cout<<"Enter the value of k: ";
    cin>>k;
    for (i = 1; i <= size; i++)
    {
        insertAtTail(head, i);
    }
    displayLinkedList(head);
    // cout << getLength(head) << endl;

    node *newHead = kAppend(head, k);
    displayLinkedList(newHead);

    // func(head);
    // displayLinkedList(head);

    return 0;
}