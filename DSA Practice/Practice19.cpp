#include <iostream>
using namespace std;
/////////////////////////////////////////
class circular_Queue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
/////////////////////////////////////////
void Queue_Traversal(circular_Queue *q)
{
    if (q->f <= q->r)
    {
        for (int i = q->f; i < q->r; i++)
        {
            cout << q->arr[i] << " ";
        }
    }
    else if (q->r<=q->f)
    {
        for (int i = q->r; i < q->f; i++)
        {
            cout << q->arr[i] << " ";
        }
    }
    
}
/////////////////////////////////////////
void enqueue(circular_Queue *&q, int value)
{
    if ((q->r + 1) % q->size == q->f)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        //cout << "R is " << q->r << endl;
        q->arr[q->r] = value;
    }
}
/////////////////////////////////////////
void Dequeue(circular_Queue *&q)
{
    if (q->r == q->f)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        //cout << "F is " << q->f << endl;
    }
}
/////////////////////////////////////////
int main()
{
    circular_Queue *q;
    q->size = 5;
    q->f = q->r = 0;
    q->arr = new int[q->size];
    ////////////////////////////////////
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    //Dequeue(q);
    // Dequeue(q);
    // enqueue(q, 5);
    // enqueue(q, 6);
    // enqueue(q, 7);
    // Dequeue(q);

    Queue_Traversal(q);

    return 0;
}