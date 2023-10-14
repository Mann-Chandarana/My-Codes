#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr, int &n)
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

vector<int> nextSmallerElement(vector<int> &arr, int &n)
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

int largestRectangleInHistogram(vector<int> &arr, int &n)
{
    vector<int> prevSmaller = prevSmallerElement(arr, n);
    // Gets prev smaller element index

    vector<int> nextSmaller = nextSmallerElement(arr, n);
    // Gets next smaller element index

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int prev = prevSmaller[i];
        int next = nextSmaller[i];

        area = max(area, (arr[i] * (next - prev - 1)));
    }

    return area;
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << largestRectangleInHistogram(heights, n) << endl;

    return 0;
}