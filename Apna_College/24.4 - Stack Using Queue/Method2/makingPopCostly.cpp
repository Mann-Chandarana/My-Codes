// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Stack
{
    queue<int> q1;
    queue<int> q2;
    int N;

public:
    Stack()
    {
        N = 0;
    }
    void push(int val) // push has O(1). 
    {
        N++;
        q1.push(val);
    }
    void pop() // pop has O(N)
    {
        if (q1.empty())
        {
            cout << "No element in Stack to pop" << endl;
            return;
        }
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();

        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int size()
    {
        return N;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << "Empty Queue ";
            return -1;
        }
        return q1.back();
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    return 0;
}