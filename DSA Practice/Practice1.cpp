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
//////////////////////////////////////////////////////////////
bool compare(node *Head, node *Head1)
{
    int s1 = size(Head);
    int s2 = size(Head1);
    int count = 0;
    if (s1 == s2)
    {
        while (Head != NULL)
        {
            if (Head->data != Head1->data)
            {
                break;
            }
            Head = Head->next;
            Head1 = Head1->next;
            count++;
            if (count == s1)
            {
                return 1;
            }
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////
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
    cout << endl;
    ///////////////////////////////////////////////////////////
    node *Head1 = new (node);
    Head1 = NULL;
    insertionATtail(Head1, 16);
    insertionATtail(Head1, 13);
    insertionATtail(Head1, 12);
    insertionATtail(Head1, 9);
    insertionATtail(Head1, 7);
    //insert_At_Node(Head1, 2, 10);
    Traversal(Head1);
    cout << endl;
    ///////////////////////////////////////////////////////////
    cout << compare(Head, Head1) << endl;

    return 0;
}