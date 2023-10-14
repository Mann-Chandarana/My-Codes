#include <bits/stdc++.h>
using namespace std;

// arr[i] >= 1

// Try for previous smaller element

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // if (arr[i] > st.top())
        // {
        //     ans[i] = st.top();
        //     st.push(arr[i]);
        // }
        // else
        // {
        //     while (st.top() >= arr[i])
        //     {
        //         st.pop();
        //     }
        //     ans[i] = st.top();
        //     st.push(arr[i]);
        // }
        while (st.top() >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = nextSmallerElement(arr, n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}