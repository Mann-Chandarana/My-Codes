#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
///////////////////////////////////////////////////////
void Traversal(node *Head)
{
    node *p = Head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << " NULL" << endl;
}
///////////////////////////////////////////////////////
void insert_At_Node(node *&Head, int index, int value)
{
    node *ptr = new (node);
    ptr->data = value;
    node *p = Head;
    int va = 0;
    while (va != index)
    {
        p = p->next;
        va++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
/////////////////////////////////////////////////////////
void Delete_Node(node *&Head, int index)
{
    node *p = Head;
    node *q = Head->next;
    int va = 0;
    while (va != index - 1)
    {
        p = p->next;
        q = q->next;
        va++;
    }
    p->next = q->next;
    delete q;
}
/////////////////////////////////////////////////////////
void insertAtHead(node *&Head, int value)
{
    node *ptr = new (node);
    ptr->data = value;
    if (Head == NULL)
    {
        ptr->next = NULL;
        Head = ptr;
        return;
    }
    ptr->next = Head;
    Head = ptr;
}
/////////////////////////////////////////////////////////
void insertionATtail(node *&Head, int value)
{
    node *ptr = new (node);
    ptr->data = value;
    if (Head == NULL)
    {
        ptr->next = NULL;
        Head = ptr;
        return;
    }
    node *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
/////////////////////////////////////////////////////////
node *reverseList(node *Head)
{
    if (Head->next == NULL || Head == NULL)
    {
        return Head;
    }
    node *newHead = reverseList(Head->next);
    Head->next->next = Head;
    Head->next = NULL;
    return newHead;
}
/////////////////////////////////////////////////////////
void ReversePrint(node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.
    if (head != NULL)
    {
        ReversePrint(head->next);
        cout << head->data << " ";
    }
}


/////////////////////////////////////////////////////////
int main()
{
    node *Head = new (node);
    Head = NULL;
    insertionATtail(Head, 16);
    insertionATtail(Head, 13);
    insertionATtail(Head, 12);
    insertionATtail(Head, 9);
    insertionATtail(Head, 7);
    insert_At_Node(Head, 2, 10);
    Traversal(Head);
    node *NewHead = reverseList(Head);
    Traversal(NewHead);

    // Delete_Node(Head, 3);
    // Traversal(Head);

    return 0;
}