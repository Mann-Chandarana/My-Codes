#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 and arr[st.top()] >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(n);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != n and arr[st.top()] >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int getAreaInHistogram(vector<int> &arr, int &n)
{
    vector<int> prev = prevSmallerElement(arr, n);

    vector<int> next = nextSmallerElement(arr, n);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (next[i] - prev[i] - 1) * arr[i]);
    }
    return ans;
}

int maxAreaWithAll1s(vector<vector<int>> &arr, int &n, int &m)
{
    vector<int> v(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j] += arr[i][j];
            }
        }

        maxArea = max(maxArea, getAreaInHistogram(v, m));
    }
    return maxArea;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    cout << maxAreaWithAll1s(v, n, m) << endl;

    return 0;
}