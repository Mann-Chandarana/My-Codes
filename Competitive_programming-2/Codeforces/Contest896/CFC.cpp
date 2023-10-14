/* https://codeforces.com/contest/1869/problem/C */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> grid(n, vector<ll>(m, -1));

    for (int j = 0; j < m; j++)
    {
        ll start = (j + 1) % m;

        for (int i = 0; i < n; i++)
        {
            grid[i][j] = start;
            start = (start + 1) % m;
            if (start == j)
                start = (start + 1) % m;
        }
    }
    if (n < m)
        cout << n + 1 << endl;
    else
    {
        if (m == 1)
            cout << 0 << endl;
        else
            cout << m << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}