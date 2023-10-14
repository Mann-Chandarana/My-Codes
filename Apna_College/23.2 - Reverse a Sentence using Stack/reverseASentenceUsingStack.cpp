#include <iostream>
#include <cstring>
using namespace std;

#define n 100

template <class T>
class stack
{
    T *arr;
    int top;

public:
    stack()
    {
        arr = new T[n];
        top = -1;
    }
    void push(T val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow";
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element in stack to pop" << endl;
        }
        top--;
    }
    T Top()
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
    string s1;
    getline(cin, s1);
    cout << s1 << endl;

    stack<char> st;

    for (int i = 0; i < s1.length(); i++)
    {
        st.push(s1[i]);
    }

    for (int i = 0; i < s1.length(); i++)
    {
        cout << st.Top();
        st.pop();
    }
    cout << endl;
    st.pop(); // Stack is empty.

    return 0;
}