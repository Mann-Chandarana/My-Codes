#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();

    insertAtBottom(s, val);

    s.push(topEle);
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    st.push(11);
    st.push(12);
    // st.push(13);
    // st.push(14);
    // st.push(15);
    // st.push(16);
    // st.push(17);
    // st.push(18);

    cout << "Before insert at bottom: ";
    printStack(st);

    insertAtBottom(st, 1);
    insertAtBottom(st, 2);
    insertAtBottom(st, 3);

    cout << "After insert at bottom: ";
    printStack(st);

    return 0;
}