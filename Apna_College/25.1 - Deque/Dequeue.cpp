#include <iostream>
using namespace std;
//////////////////////////////////////////////////
class Dequeue
{
public:
    int size;
    int f;
    int r;
    int *arr;
};
//////////////////////////////////////////////////
void enqueue_Front(Dequeue *&q, int value)
{
    if ((q->f == q->r + 1) || (q->f == 0 && q->r == q->size - 1))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (q->f == -1 && q->r == -1)
    {
        q->f = q->r = 0;
        q->arr[q->f] = value;
    }
    else if (q->f == 0)
    {
        q->f = q->size - 1;
        q->arr[q->f] = value;
    }
    else
    {
        q->f--;
        q->arr[q->f] = value;
    }
}
//////////////////////////////////////////////////
void enqueue_Rear(Dequeue *&q, int value)
{
    if ((q->f == q->r + 1) || (q->f == 0 && q->r == q->size - 1))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (q->f == -1 && q->r == -1)
    {
        q->f = q->r = 0;
        q->arr[q->r] = value;
    }
    else if (q->r = q->size - 1)
    {
        q->r = 0;
        q->arr[q->r] = value;
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}
//////////////////////////////////////////////////
void Dequeue_rear(Dequeue *&q)
{
    if (q->f == -1 && q->r == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (q->r == q->f)
    {
        q->r = q->f = -1;
    }
    else if (q->r == 0)
    {
        q->r = q->size - 1;
    }
    else
    {
        q->r--;
    }
}
//////////////////////////////////////////////////
void Dequeue_front(Dequeue *&q)
{
    if (q->f == -1 && q->r == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (q->r == q->f)
    {
        q->f = q->r = -1;
    }
    else if (q->f == q->size - 1)
    {
        q->f = 0;
    }
    else
    {
        q->f++;
    }
}
//////////////////////////////////////////////////
void display(Dequeue *q)
{

    for (int i = q->f; i != q->r;)
    {
        cout << q->arr[i] << " ";
        i = (i + 1) % q->size;
    }
}
//////////////////////////////////////////////////
int main()
{
    Dequeue *q;
    q->r = q->f = -1;
    q->size = 5;
    q->arr = new int[q->size];

    enqueue_Front(q, 5);
    enqueue_Front(q, 4);
    enqueue_Front(q, 3);
    enqueue_Front(q, 2);
    enqueue_Front(q, 1);
    //enqueue_Front(q, 0);

    display(q);
    Dequeue_rear(q);
    Dequeue_rear(q);
    cout << "\n";
    display(q);

    // cout << "\n";
    // enqueue_Rear(q, 6);
    // enqueue_Rear(q, 7);
    // enqueue_Rear(q, 8);
    // enqueue_Rear(q, 9);
    // display(q);

    // cout << "\n";
    // Dequeue_front(q);
    // Dequeue_front(q);
    // display(q);

    return 0;
}