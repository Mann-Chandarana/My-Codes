// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

// Return true if there are redundant parenthesis. If there are not then return false;
bool redundantParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')') // Used else if here so that space character doesnot take memory in the stack.
        {
            if (st.empty() || st.top() == '(')
            {
                return true;
            }
            while (!st.empty() && st.top() != '(')
            {
                st.pop();
            }
            st.pop(); // to pop the '(' character.
        }
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    cout << redundantParenthesis(s) << endl;

    return 0;
}