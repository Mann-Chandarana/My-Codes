#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t, ele, q;
    cin >> t;
    stack<int> st;
    stack<int> mx;
    mx.push(0);

    while (t--)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> ele;
            if (ele > mx.top())
            {
                mx.push(ele);
            }

            st.push(ele);
        }
        else if (q == 2)
        {
            if (st.top() == mx.top())
            {
                mx.pop();
            }
            st.pop();
        }
        else if (q == 3)
        {
            cout << mx.top() << endl;
        }
    }

    return 0;
}