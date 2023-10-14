#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

/*
    Note:
    Here we start form left to right in the string.
*/

int postfixEvaluation(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top(); // Note: here first top element will be stored in op2.
            // Whereas in prefix evaluation first top element gets stored in op1.
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s = "46+2/5*7+";
    cout << postfixEvaluation(s) << endl;

    return 0;
}