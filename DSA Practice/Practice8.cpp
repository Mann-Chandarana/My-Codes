#include <iostream>
using namespace std;
/////////////////////////////////////////
class Node
{
public:
    int data;
    Node *next;
};
/////////////////////////////////////////
bool isFull(Node *sp)
{
    Node *p = new (Node);
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/////////////////////////////////////////
Node *push(Node *sp, int value)
{
    if (isFull(sp))
    {
        cout << "Stack is full" << endl;
        return sp;
    }
    else
    {
        Node *n = new (Node);
        n->data = value;
        n->next = sp;
        return n;
    }
}
/////////////////////////////////////////
bool isEmpty(Node *sp)
{
    if (sp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/////////////////////////////////////////
void pop(Node *&sp)
{
    if (isEmpty(sp))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    else
    {
        Node *top = sp;
        sp = sp->next;
        free(top);
    }
}
/////////////////////////////////////////
void tp(Node *sp)
{
    cout << sp->data << endl;
}
/////////////////////////////////////////
int peek(Node *sp, int pos)
{
    Node *ptr = sp;
    for (int i = 0; i < (pos - 1) && (ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    Node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);

    for (int i = 1; i <= 4; i++)
    {
        cout << peek(top, i) << endl;
    }

    // pop(top);
    // pop(top);
    // cout << isEmpty(top);
    // pop(top);

    return 0;
}