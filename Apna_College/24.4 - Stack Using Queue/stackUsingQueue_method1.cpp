#include <bits/stdc++.h>
using namespace std;

// Making psuh costly.

class Stack
{
    int N; // For getting the size of the stack.
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }
    void push(int val) // O(N)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() // O(1)
    {
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return N;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "The size is: " << st.size() << endl;
    cout << st.top() << endl;

    st.pop();
    st.pop();
    st.pop();

    cout << st.top() << endl;

    return 0;
}