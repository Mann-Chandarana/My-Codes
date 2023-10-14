#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

/*
    Explanation:
    Start reading the string from the right side. If an operand character comes push it into the stack.
    If an operator character comes pop one value and save it to op1 and again pop one value and save it to op1;
    (if stack is 1 2 3 where 3 is top then, op1 = 3 and op2 = 2).
    Perform the operation given as the operator character and push the value back to stack.
    (int 1 2 3 if - comes then, op1 = 3 and op2 = 2 => op1 - op2 = 3-2 = 1. Push back 1 into the stack)
    (New stack is 1 1). 
*/

int prefixEvaluation(string s)
{
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // For converting character to int.
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '*':
                st.push(op1 * op2);
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
    string s = "-+7*45+20";
    int ans = prefixEvaluation(s);
    cout << ans << endl;

    return 0;
}
