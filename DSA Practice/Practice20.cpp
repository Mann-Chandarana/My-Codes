#include <iostream>
using namespace std;
/////////////////////////////////////
class Node
{
public:
    int data;
    Node *next;
};
/////////////////////////////////////
class Queue
{
public:
    Node *f = NULL;
    Node *r = NULL;
};
/////////////////////////////////////
void Enqueue(Queue *&q, int value)
{
    Node *n = new (Node);
    n->data = value;
    n->next = NULL;
    if (n == NULL)
    {
        cout << "Queue is full " << endl;
    }
    else
    {
        if (q->f == NULL)
        {
            q->f = n;
            q->r = n;
        }
        q->r->next = n;
        q->r = n;
    }
}
/////////////////////////////////////
void Dequeue(Queue *&q)
{
    Node *ptr = q->f;
    if (q->f == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        q->f = q->f->next;
        delete (ptr);
    }
}
/////////////////////////////////////
void Traversal(Queue *q)
{
    Node *ptr = q->f;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
/////////////////////////////////////
int main()
{
    Queue *q;
    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);
    Traversal(q);
    Dequeue(q);
    Dequeue(q);
    Traversal(q);

    return 0;
}