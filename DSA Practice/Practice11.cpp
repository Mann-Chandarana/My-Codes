#include <iostream>
#include <stack>
using namespace std;
////////////////////////////////
stack<int> reverse_stack(stack<int> sp)
{
    stack<int> st;
    while (!sp.empty())
    {
        int x = sp.top();
        st.push(x);
        sp.pop();
    }
    return st;
}
int main()
{
    stack<int> sp;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sp.push(x);
    }
    cout << sp.top() << endl;
    stack<int> st = reverse_stack(sp);
    cout << st.top() << endl;
    // while (!st.empty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    return 0;
}