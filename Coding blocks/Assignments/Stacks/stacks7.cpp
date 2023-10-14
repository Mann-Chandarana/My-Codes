////////////// Importance of time

#include <bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////
void insertBottom(stack<int> &st)
{
    int ele = st.top();
    st.pop();

    stack<int> s2;
    while (!st.empty())
    {
        s2.push(st.top());
        st.pop();
    }
    st.push(ele);

    while (!s2.empty())
    {
        st.push(s2.top());
        s2.pop();
    }
}
/////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////
int IMP_Time(stack<int> st, stack<int> st1)
{
    if (st.empty() || st1.empty())
    {
        return -1;
    }

    int total_time = 0, count = 0;

    while (!st.empty() && !st1.empty())
    {
        if (st.top() == st1.top())
        {
            total_time++;
        }
        else
        {
            while (st.top() != st1.top())
            {
                insertBottom(st);
                count++;
            }
            total_time += count + 1;
            count = 0;
        }
        st.pop();
        st1.pop();
    }

    return total_time;
}
///////////////////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n), vec1(n);
    stack<int> st, st1;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        st.push(vec[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i];
        st1.push(vec1[i]);
    }
    Reverse_stack(st);
    Reverse_stack(st1);

    cout << IMP_Time(st, st1) << endl;

    return 0;
}