// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void reverseString(string &s)
{
    stack<char> st;

    while (s.length() != 0)
    {
        st.push(s[0]);
        s.erase(s.begin());
    }

    while (!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }
}

int main()
{
    string s;
    cin >> s;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    cout << "String: " << s << endl;

    cout << "Reversed string: ";
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    cout << "Before: " << s << endl;
    reverseString(s);
    cout << "After: " << s << endl;

    return 0;
}