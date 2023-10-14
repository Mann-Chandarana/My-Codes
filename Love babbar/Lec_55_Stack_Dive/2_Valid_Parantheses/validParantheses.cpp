#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        /*
        // if (s[i] == '(' or s[i] == '[' or s[i] == '{') // Any open bracket
        //     st.push(s[i]);

        // else if (st.empty()) // Close bracket come but the stack is empty (Which means no open bracket)
        //     return false;

        // else if ((s[i] == ')' and st.top() == '(')
        //          or (s[i] == '}' and st.top() == '{') or (s[i] == ']' and st.top() == '['))
        // {
        //     // Close bracket comes and the same open bracket is the top of the stack
        //     st.pop();
        // }

        // else // Close bracket comde but the top of the stack is different tha the open bracket for tha close bracket
        //     return false;
        */

        if (s[i] == '(' or s[i] == '[' or s[i] == '{') // Any open bracket
            st.push(s[i]);
        else // Close bracket comes
        {
            if (st.empty()) // If the stack is empty
                return false;

            if ((s[i] == ')' and st.top() == '(') or (s[i] == '}' and st.top() == '{') or (s[i] == ']' and st.top() == '['))
            {
                // Close bracket comes and the same open bracket is the top of the stack
                st.pop();
            }
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    if (isValidParenthesis(s))
        cout << "Valid" << endl;
    else
        cout << "In valid" << endl;

    return 0;
}