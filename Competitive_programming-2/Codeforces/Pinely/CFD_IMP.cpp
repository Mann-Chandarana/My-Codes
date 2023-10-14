/* https://codeforces.com/contest/1863/problem/D */

/*
Row should contain even number of 'U'
Col should contain even number of 'L'
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<string> ans;
    vector<string> vec;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        ans.push_back(s);
        vec.push_back(s);
    }

    vector<char> row(n, 'B');
    vector<char> col(m, 'B');

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (vec[i][j] == 'U')
            {
                if (row[i] == 'B')
                {
                    ans[i][j] = 'W';
                    row[i] = 'W';
                    ans[i + 1][j] = 'B';
                }
                else
                {
                    ans[i][j] = 'B';
                    row[i] = 'B';
                    ans[i + 1][j] = 'W';
                }
            }
            else if (vec[i][j] == 'L')
            {
                if (col[j] == 'B')
                {
                    ans[i][j] = 'W';
                    col[j] = 'W';
                    ans[i][j + 1] = 'B';
                }
                else
                {
                    ans[i][j] = 'B';
                    col[j] = 'B';
                    ans[i][j + 1] = 'W';
                }
            }
        }
    }

    bool check = true;

    for (int i = 0; i < n; i++)
    {
        if (row[i] != 'B')
            check = false;
    }

    for (int i = 0; i < m; i++)
    {
        if (col[i] != 'B')
            check = false;
    }

    if (!check)
        cout << -1 << endl;
    else
        for (auto i : ans)
            cout << i << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}