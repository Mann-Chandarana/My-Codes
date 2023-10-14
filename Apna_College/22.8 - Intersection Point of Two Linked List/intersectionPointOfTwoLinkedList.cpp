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

int getLength(node *head)
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

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    while ((pos - 1))
    {
        temp1 = temp1->next;
        pos--;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersectionPoint(node *&head1, node *&head2)
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);
    int d;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {9, 10};
    node *head1 = NULL;
    node *head2 = NULL;
    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); i++)
    {
        insertAtTail(head1, arr1[i]);
    }

    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    int l1, l2;
    l1 = getLength(head1);
    l2 = getLength(head2);

    if (l1 > 2)
    { 
        intersect(head1, head2, (l2 + 1)); // We can also give a specific position for insertion. pos = 5.
    }
    else
    {
        intersect(head2, head1, (l1 + 1));
    }
    cout<<"\nLinked List1 :\n";
    displayLinkedList(head1);
    cout<<"\nLinked List2 :\n";
    displayLinkedList(head2);
    cout << "\nThe value of intersection point of the given two linked list: "
         << intersectionPoint(head1, head2) << endl << endl;

    return 0;
}