#include <iostream>
#include <stack>
using namespace std;
///////////////////////////////////////////
class Queue
{
public:
    stack<int> s;
    void push(int val)
    {
        s.push(val);
    }
    int pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty" << endl;
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
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}