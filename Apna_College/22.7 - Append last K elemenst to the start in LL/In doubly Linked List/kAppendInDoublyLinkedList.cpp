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
    n->prev = temp;
}

void displayLinkedList(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *kAppend(node *&head, int k)
{
    int len = getLength(head);
    node *tail = head;
    node *newHead;
    node *newTail;
    int m = 0;
    k = k % len;
    if(k==0)
        return head;
    while (tail != NULL)
    {
        m++;
        if (m == (len - k))
        {
            newTail = tail;
        }
        if (m == (len - k + 1))
        {
            newHead = tail;
        }
        if(tail->next == NULL)
            break;
        tail = tail->next;
    }

    tail->next = head;
    newTail->next = NULL;
    newHead->prev = NULL;

    return newHead;
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

    node *newHead = kAppend(head, k);
    displayLinkedList(newHead);

    return 0;
}