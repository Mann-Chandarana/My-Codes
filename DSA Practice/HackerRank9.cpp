#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, query, x, max = 0;
    stack<int> st;
    stack<int> mx;
    cin >> n;
    while (n--)
    {
        cin >> query;
        if (query == 1)
        {
            cin >> x;
            st.push(x);
            if (st.top() > max)
            {
                max = st.top();
                mx.push(max);
            }
        }
        else if (query == 2)
        {
            st.pop();
        }

        else if (query == 3)
        {
            cout << mx.top()<<endl;
        }
    }

    return 0;
}