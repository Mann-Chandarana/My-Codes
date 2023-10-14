#include <iostream>
using namespace std;

#define n 100

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflaw" << endl;
            return;
        }
        back++;
        arr[back] = val;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No elements in Queue" << endl;
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Empty Queue " ;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();

    return 0;
}