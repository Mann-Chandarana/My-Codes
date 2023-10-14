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
///////////////////////////////////////////////////////
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
int size(node *Head)
{
    node *ptr = Head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
/////////////////////////////////////////////////////////
void make_cycle(node *&Head, int index)
{
    node *ptr = Head;
    node *p = Head;
    int count = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (count != index - 1)
    {
        p = p->next;
        count++;
    }
    ptr->next = p;
}
/////////////////////////////////////////////////////////
bool detect_Cycle(node *Head)
{
    node *fast, *slow;
    fast = Head;
    slow = Head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
/////////////////////////////////////////////////////////
int main()
{
    node *Head = new (node);
    Head = NULL;
    insertionATtail(Head, 1);
    insertionATtail(Head, 2);
    insertionATtail(Head, 3);
    insertionATtail(Head, 4);
    insertionATtail(Head, 5);
    insertionATtail(Head, 6);
    insertionATtail(Head, 7);
    make_cycle(Head, 3);
    cout << detect_Cycle(Head) << endl;
    return 0;
}
