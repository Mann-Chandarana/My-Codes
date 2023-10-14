#include "bits/stdc++.h"
using namespace std;

class Queue
{
    stack<int> s;

public:
    void push(int val)
    {
        s.push(val);
    }
    int pop()
    {
        if (s.empty())
        {
            cout << "Empty Queue ";
            return -1;
        }
        int x = s.top();
        s.pop();
        if (s.empty())
        {
            return x;
        }
        int item = pop();
        s.push(x);
        return item;
    }
    bool empty()
    {
        if (s.empty())
            return true;
        return false;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    q.push(100);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}