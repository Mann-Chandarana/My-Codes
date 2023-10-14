#include <iostream>
using namespace std;

// int n = 100;

// Define n using define keyword.
#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element in stack to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.empty() << endl;
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // cout << st.Top() << endl;
    cout << st.empty() << endl;
    st.push(70);
    cout << st.Top() << endl;

    return 0;
}