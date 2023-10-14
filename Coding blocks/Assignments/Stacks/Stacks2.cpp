/////// Stocks span

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *cnt = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vec(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        bool is_false = false;
        while (!st.empty() && curr >= st.top())
        {
            cnt[i] += cnt[i - 1] + 1;
            st.pop();
            is_false = true;
        }
        st.push(curr);
        if (!is_false)
        {
            cnt[i] += 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << "END" << endl;

    return 0;
}