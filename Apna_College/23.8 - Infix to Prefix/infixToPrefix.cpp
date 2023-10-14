#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
/*
First reverse the string. convert the forward brackets to backward brackets and vice versa.
    if infix expression if (a-b/c)*(a/k-l)
    reverse: )l-k/a(*)c/b-a(
    Converting the brackets: (l-k/a)*(c/b-a)
    Why? => So we can implement the same logic we implemented fot infix to postfix.
*/

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '/' || c == '*')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        /*
        // if (s[i] == ')')
        // {
        //     s[i] == '(';
        // }
        // else if (s[i] == '(')
        // {
        //     s[i] == ')';
        // }
        */
        else if (s[i] == ')') // Taken ')' insted of '(' so that we dont need to reverse them.
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (prec(st.top()) >= prec(s[i])))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << infixToPrefix("(a-b/c)*(a/k-l)") << endl;
    return 0;
}
// (a-b/c)*(a/k-l)
// )l-k/a(*)c/b-a(