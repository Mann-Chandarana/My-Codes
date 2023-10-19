/* C. Perfect Square  */

/* https://codeforces.com/contest/1881/problem/C */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve()
{
    int n;
    cin >> n;
 
    vector<vector<char>> mat(n, vector<char>(n));
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
 
    ll ans = 0;
 
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            char c = max({mat[i][j], mat[n - 1 - j][i], mat[n - 1 - i][n - 1 - j], mat[j][n - 1 - i]});
            ans += abs(c - mat[i][j]) + abs(c - mat[n - 1 - j][i]) + abs(c - mat[n - 1 - i][n - 1 - j]) + abs(c - mat[j][n - 1 - i]);
        }
    }
    cout << ans << endl;
}
 
int main()
{
    int t;
    cin >> t;
 
    while (t--)
        solve();
 
    return 0;
}