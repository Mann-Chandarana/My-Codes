#include <iostream>
#include <stack>
using namespace std;
//////////////////////////////////////////
int prefix_Evaluation(string s)
{
    stack<int> st;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int opd1 = st.top();
            st.pop();
            int opd2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(opd1 + opd2);
                break;
            case '-':
                st.push(opd1 - opd2);
                break;
            case '*':
                st.push(opd1 * opd2);
                break;
            case '/':
                st.push(opd1 / opd2);
                break;
            case '^':
                st.push(opd1 ^ opd2);
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
    int ans = prefix_Evaluation(s);
    cout << ans << endl;
    return 0;
}