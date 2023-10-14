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
node *merge_Sorted_list(node *&Head, node *&Head1)
{
    node *ptr = new (node);
    node *Dummy_node = ptr;
    int s1 = size(Head);
    int s2 = size(Head1);

    while (Head != NULL && Head1 != NULL)
    {
        if (Head->data <= Head1->data)
        {
            Dummy_node->next = Head;
            Head = Head->next;
        }
        else
        {
            Dummy_node->next = Head1;
            Head1 = Head1->next;
        }
        Dummy_node = Dummy_node->next;
    }
    while (Head != NULL)
    {
        Dummy_node->next = Head;
        Head = Head->next;
        Dummy_node = Dummy_node->next;
    }
    while (Head1 != NULL)
    {
        Dummy_node->next = Head1;
        Head1 = Head1->next;
        Dummy_node = Dummy_node->next;
    }
    return ptr;
}
/////////////////////////////////////////////////////////
int value_from_Tail(node *Head, int index)
{
    int s1 = size(Head);
    int in = s1 - (index+1);
    int count = 0;
    while (count != in)
    {
        Head = Head->next;
        count++;
    }
    return Head->data;
}
/////////////////////////////////////////////////////////
int main()
{
    node *Head = new (node);
    Head = NULL;
    insertionATtail(Head, 3);
    insertionATtail(Head, 2);
    insertionATtail(Head, 1);
    insertionATtail(Head, 0);
    Traversal(Head);
    cout << value_from_Tail(Head, 2) << endl;
    cout << endl;
    ///////////////////////////////////////////////////////////
    // node *Head1 = new (node);
    // Head1 = NULL;
    // insertionATtail(Head1, 1);
    // insertionATtail(Head1, 2);
    // insertionATtail(Head1, 5);
    // insertionATtail(Head1, 6);
    // insertionATtail(Head1, 11);
    // Traversal(Head1);
    // cout << endl;
    // ///////////////////////////////////////////////////////////
    // node *newHead = merge_Sorted_list(Head, Head1);
    // Traversal(newHead->next);

    return 0;
}