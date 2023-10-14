#include <bits/stdc++.h>
using namespace std;

void insertAtCorrectPos(stack<int> &s, int &ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }

    if (s.top() > ele)
    {
        int topEle = s.top();
        s.pop();

        insertAtCorrectPos(s, ele);

        s.push(topEle);
    }
    else
        s.push(ele);
}

void stackSort(stack<int> &s)
{
    if (s.empty())
        return;

    int topEle = s.top();
    s.pop();

    stackSort(s);

    insertAtCorrectPos(s, topEle);
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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        st.push(temp);
    }

    printStack(st);

    stackSort(st);

    printStack(st);

    return 0;
}