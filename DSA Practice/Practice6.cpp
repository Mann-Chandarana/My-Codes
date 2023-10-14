#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////
class node
{
public:
    int data;
    node *next;
    node *prev;
};
/////////////////////////////////////////////////////////
void display(node *Head)
{
    node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
/////////////////////////////////////////////////////////
void insert_At_Tail(node *&Head, int value)
{
    node *ptr = new (node);

    ptr->data = value;
    if (Head == NULL)
    {
        ptr->next = NULL;
        Head = ptr;
    }
    node *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
}
/////////////////////////////////////////////////////////
void insert_At_Given_Node(node *&Head, int value)
{
    node *p = Head;
    node *q = Head->next;
    node *ptr = new (node);
    ptr->data = value;
    while (p->data < value)
    {
        p = p->next;
    }
    p = p->prev;
    q = p->next;
    ptr->next = q;
    q->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
}
/////////////////////////////////////////////////////////
void Reverse_Traversal(node *Head)
{
    Head->prev = NULL;
    node *ptr = Head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " <-> ";
        ptr = ptr->prev;
    }
    cout << " NULL" << endl;
}
/////////////////////////////////////////////////////////
int main()
{
    node *Head = new (node);
    Head = NULL;
    insert_At_Tail(Head, 1);
    insert_At_Tail(Head, 2);
    insert_At_Tail(Head, 3);
    insert_At_Tail(Head, 5);
    insert_At_Tail(Head, 6);
    insert_At_Given_Node(Head, 4);
    display(Head);
    cout << endl;
    Reverse_Traversal(Head);

    return 0;
}