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
void intersect(node *Head, node *Head1, int pos)
{
    while (pos - 1)
    {
        Head = Head->next;
        pos--;
    }
    while (Head1->next != NULL)
    {
        Head1 = Head1->next;
    }
    Head1->next = Head;
}
/////////////////////////////////////////////////////////
int merge_point_of_two_list(node *Head, node *Head1)
{
    int s1 = size(Head);
    int s2 = size(Head1);
    int d;
    node *ptr, *ptr1;
    if (s1 > s2)
    {
        d = s1 - s2;
        ptr = Head;
        ptr1 = Head1;
    }
    else
    {
        d = s2 - s1;
        ptr = Head1;
        ptr1 = Head;
    }
    while (d)
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            return 0;
        }
        d--;
    }
    while ((ptr != NULL) && (ptr1 != NULL))
    {
        if (ptr->data == ptr1->data)
        {
            return ptr->data;
        }
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    return 0;
}
int main()
{
    node *Head = new (node);
    Head = NULL;
    insertionATtail(Head, 1);
    insertionATtail(Head, 2);
    insertionATtail(Head, 3);
    insertionATtail(Head, 4);
    insertionATtail(Head, 5);
    node *Head1 = new (node);
    Head1 = NULL;
    insertionATtail(Head1, 6);
    insertionATtail(Head1, 7);
    insertionATtail(Head1, 8);
    //intersect(Head, Head1, 4);
    cout<<merge_point_of_two_list(Head,Head1)<<endl;
    return 0;
}