#include <bits/stdc++.h>
using namespace std;

// Implement stack using queue: Homework

// Stack using queue
class Stack
{
    queue<int> q;

public:
    void push(int d)
    {
        int size = q.size();
        q.push(d);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is already empty" << endl;
            return;
        }
        q.pop();
    }
    int top()
    {
        if (q.empty())
        {
            cout << "Stack is already empty";
            return -1;
        }
        return q.front();
    }
    int size()
    {
        return q.size();
    }
    bool empty()
    {
        return q.empty();
    }
};

// Queue using stack
class Queue
{
    stack<int> st;

    void pushAtBottom(stack<int> &st, int &d)
    {
        if (st.empty())
        {
            st.push(d);
            return;
        }

        int top = st.top();
        st.pop();

        pushAtBottom(st, d);

        st.push(top);
    }

public:
    void push(int data) // O(N)
    {
        pushAtBottom(st, data);
    }

    int front() // O(1)
    {
        if (st.empty())
        {
            cout << "Queue is empty ";
            return -1;
        }
        return st.top();
    }

    void pop() // O(1)
    {
        if (st.empty())
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        st.pop();
    }

    int size() // O(1)
    {
        return st.size();
    }

    bool empty() // O(1)
    {
        return st.empty();
    }
};

int main()
{
    // Queue using stack
    /*

    Queue q;

    cout << q.front() << endl;
    cout << "Empty: " << q.empty() << endl;

    q.push(11);
    q.push(12);
    q.push(13);

    cout << q.front() << endl;
    cout << "Size: " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << q.front() << endl;
    */

    // Stack using queue
    /*
    Stack st;

    cout << "Empty: " << st.empty() << endl;

    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);

    cout << "Size: " << st.size() << endl;
    cout << "Top: " << st.top() << endl;

    st.pop();
    cout << "Size: " << st.size() << endl;
    cout << "Top: " << st.top() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "Size: " << st.size() << endl;
    cout << st.top() << endl;
    */

    return 0;
}