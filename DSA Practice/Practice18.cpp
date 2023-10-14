#include <iostream>
using namespace std;
///////////////////////////////////////////////////
class Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
///////////////////////////////////////////////////
void Queue_Traversal(Queue *q)
{
    for (int i = q->f+1; i < q->r; i++)
    {
        cout << q->arr[i] << " ";
    }
}
///////////////////////////////////////////////////
void enqueue(Queue *&q, int value)
{
    if (q->r == q->size - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}
///////////////////////////////////////////////////
int Dequeue(Queue *&q)
{
    if (q->r == q->f)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        int x = q->arr[q->f];
        q->f++;
        return x;
    }
}
///////////////////////////////////////////////////

int main()
{
    Queue *q;
    q->f = q->r = -1;
    q->size = 10;
    q->arr = new int[q->size];

    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    Queue_Traversal(q);
    return 0;
}