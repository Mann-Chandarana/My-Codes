#include <iostream>
#include <queue>
using namespace std;
////////////////////////////////////////////////////
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
        q2.push(value);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        N++;
    }
    void pop(void)
    {
        q1.pop();
        N--;
    }
    int size(void)
    {
        return N;
    }
    int top()
    {
        return q1.front();
    }
};
////////////////////////////////////////////////////
int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout << s1.top() << endl;
    s1.pop();
    s1.pop();
    cout << s1.top() << endl;
    
    return 0;
}