#include <iostream>
#include <stack>
using namespace std;
/////////////////////////////////////////////////////
bool ismatch(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())
            {
                st.push(' ');
            }

            if (st.top() == '(' && s[i] == ')' && !st.empty())
            {
                st.pop();
            }
            else if (st.top() == '{' && s[i] == '}' && !st.empty())
            {
                st.pop();
            }
            else if (st.top() == '[' && s[i] == ']' && !st.empty())
            {
                st.pop();
            }
            else
            {

                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    if (!st.empty())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
////////////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        if (ismatch(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}