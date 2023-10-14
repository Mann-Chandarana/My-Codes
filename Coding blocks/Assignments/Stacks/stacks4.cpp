#include <bits/stdc++.h>
using namespace std;

void insertATbottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int curr = st.top();
    st.pop();

    insertATbottom(st, ele);
    st.push(curr);
}

void Reverse_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int element = s.top();
    s.pop();
    Reverse_stack(s);

    insertATbottom(s, element);
}

int main()
{
    int n, ele;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        st.push(ele);
    }
    Reverse_stack(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
