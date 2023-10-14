//////// Histogram

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<ll> nextSmallerElement(vector<ll> arr, ll n)
{
    stack<ll> s;
    s.push(-1);
    vector<ll> ans(n);

    for (ll i = n - 1; i >= 0; i--)
    {
        ll curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<ll> prevSmallerElement(vector<ll> arr, ll n)
{
    stack<ll> s;
    s.push(-1);
    vector<ll> ans(n);

    for (ll i = 0; i < n; i++)
    {
        ll curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

ll largestRectangleArea(vector<ll> &heights)
{
    ll n = heights.size();
    vector<ll> next(n);
    next = nextSmallerElement(heights, n);

    vector<ll> prev(n);
    prev = prevSmallerElement(heights, n);

    ll area = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }
        ll b = next[i] - prev[i] - 1;
        ll newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestRectangleArea(arr) << endl;

    return 0;
}