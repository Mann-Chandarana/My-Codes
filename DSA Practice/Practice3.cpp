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
///////////////////////////////////////////////////////////
node *Delete_repetition(node *&Head)
{
    node *ptr = Head;
    node *temp = NULL;
    node *tem = NULL;
    while ((ptr != NULL) && (ptr->next != NULL))
    {
        temp = ptr->next;
        while ((temp != NULL) && ptr->data == temp->data)
        {
            tem = temp;
            temp = temp->next;
            tem->next = NULL;
            delete (tem);
        }
        ptr->next = temp;
        ptr = temp;
    }
    return Head;
}

int main()
{
    node *Head = new (node);
    Head = NULL;
    insertionATtail(Head, 1);
    insertionATtail(Head, 2);
    insertionATtail(Head, 2);
    insertionATtail(Head, 3);
    insertionATtail(Head, 3);
    insertionATtail(Head, 3);
    insertionATtail(Head, 3);
    Traversal(Head);
    cout << endl;
    node *newHead = new (node);
    newHead = Delete_repetition(Head);
    Traversal(newHead);

    return 0;
}