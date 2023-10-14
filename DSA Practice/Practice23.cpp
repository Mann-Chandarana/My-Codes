#include <iostream>
#include <queue>
using namespace std;
//////////////////////////////////////////
class stack
{
    queue<int> q1;
    queue<int> q2;
    int N;

public:
    stack()
    {
        N = 0;
    }
    void push(int value)
    {
        q1.push(value);
        N++;
    }
    void pop(void)
    {
        if (q1.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            return q1.back();
        }
    }
    int size()
    {
        return N;
    }
};
//////////////////////////////////////////
int main()
{
    stack s1;
    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    return 0;
}