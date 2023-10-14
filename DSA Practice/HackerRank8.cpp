#include <iostream>
using namespace std;
///////////////////////////////
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
///////////////////////////////
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
///////////////////////////////
void insert_Node_at_tail(Node *&Head, int value)
{
    Node *temp = new (Node);
    temp->data = value;
    if (Head == NULL)
    {

        temp->next = NULL;
        Head = temp;
    }

    Node *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
    temp->prev = p;
}
///////////////////////////////
void insert_Element_in_sorted_list(Node *&Head, int value)
{
    Node *temp = new (Node);
    temp->data = value;
    Node *p = Head;
    Node *q = new (Node);
    while (p->data < value)
    {
        p = p->next;
    }
    p = p->prev;
    q = p->next;
    temp->next = q;
    q->prev = temp;
    p->next = temp;
    temp->prev = p;
}
///////////////////////////////
void Reverse_Traversal(Node *Head)
{
    Head->prev = NULL;
    Node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;

}
///////////////////////////////
int main()
{
    Node *Head = new (Node);
    Head = NULL;
    int n, element, value;
    cin >> n;
    while (n--)
    {
        cin >> element;
        insert_Node_at_tail(Head, element);
    }
    //display(Head);
    Reverse_Traversal(Head);
    // cin >> value;
    // insert_Element_in_sorted_list(Head, value);
    // display(Head);

    return 0;
}