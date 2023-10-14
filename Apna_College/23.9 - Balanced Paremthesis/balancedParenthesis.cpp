#include <iostream>
#include <stack>
using namespace std;

bool balancedParenthesis(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == '(') or (s[i] == '[') or (s[i] == '{'))
        {
            st.push(s[i]);
        }
        else if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
        {
            if (!st.empty() and s[i] == ')' and st.top() == '(')
            {
                st.pop();
            }
            else if (!st.empty() && s[i] == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (!st.empty() && s[i] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
            }
        }
    }

    if(!st.empty())
    {
        ans = false;
    }
    return ans;
}

int main()
{
    string s1 = "({[()]})";
    cout << balancedParenthesis(s1) << endl;
    string s2 = "({[}]";
    cout << balancedParenthesis(s2) << endl;

    return 0;
}