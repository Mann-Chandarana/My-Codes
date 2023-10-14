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

node *mergeTwoSortedLinkedList(node *&head1, node *&head2)
{
    node *newHead = NULL;
    node *temp1 = head1;
    node *temp2 = head2;
    if (head1 == NULL) // Check wether any of the linked list is empty or not.
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    if (temp1->data < temp2->data) // For getting the first element (Head element).
    {
        newHead = temp1;
        temp1 = temp1->next;
    }
    else
    {
        newHead = temp2;
        temp2 = temp2->next;
    }
    node *newTemp = newHead; // Traversing in the new linked list.
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            newTemp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            newTemp->next = temp2;
            temp2 = temp2->next;
        }
        newTemp = newTemp->next;
    }
    while (temp1 != NULL) // If there are still elements in ll1.
    {
        newTemp->next = temp1;
        temp1 = temp1->next;
        newTemp = newTemp->next;
    }
    while (temp2 != NULL) // If there are still elements in ll2.
    {
        newTemp->next = temp2;
        temp2 = temp2->next;
        newTemp = newTemp->next;
    }
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

node* mergeUsingRecursion(node *&head1,node *&head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    node *result;

    if(head1->data < head2->data)
    {
        result = head1;
        result->next = mergeUsingRecursion(head1->next,head2);
    }
    else
    {
        result = head2;
        result->next = mergeUsingRecursion(head1,head2->next);
    }

    return result;

}

int main()
{
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {1, 3, 6};
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

    // node *newHead = mergeTwoSortedLinkedList(head1, head2);
    node *newHead = mergeUsingRecursion(head1, head2);
    displayLinkedList(newHead);

    return 0;
}