#include <iostream>
using namespace std;
////////////////////////////////
class Node
{
public:
    int data;
    Node *next;
};
//////////////////////////////
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void delete_Node(Node *&Head, int index)
{
    Node *ptr = Head;
    Node *p = Head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
}
///////////////////////////////
void insert_at_head(Node *&head, int value)
{
    Node *ptr;
    ptr = new (Node);
    ptr->data = value;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return;
    }

    ptr->next = head;
    head = ptr;
}
///////////////////////////////
void insert_end(Node *&head, int value)
{

    Node *ptr;
    ptr = new (Node);
    ptr->data = value;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return;
    }

    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
//////////////////////////////////////
Node *reverseList(Node *Head)
{
    Node *previousPtr = NULL;
    Node *currentPtr = Head;
    Node *nextPtr;
    nextPtr = new (Node);
    while (currentPtr != NULL)
    {
        nextPtr = currentPtr->next;
        currentPtr->next = previousPtr;
        previousPtr = currentPtr;
        currentPtr = nextPtr;
    }
    Head = previousPtr;
    return Head;
}
////////////////////////////////////////
void ReversePrint(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    if (head != NULL)
    {
        ReversePrint(head->next);
        cout << head->data << " ";
    }
}
int main()
{
    Node *Head;
    Head = NULL;
    int n, n1, element;
    cin >> n;
    while (n--)
    {
        cin >> element;
        insert_end(Head, element);
    }
    display(Head);
    cout << endl;
    ReversePrint(Head);
    // cout << endl;
    // Head = reverseList(Head);
    // display(Head);

    // cin >> n1;
    // display(Head);
    // delete_Node(Head, 3);
    // cout << endl;
    // display(Head);

    return 0;
}