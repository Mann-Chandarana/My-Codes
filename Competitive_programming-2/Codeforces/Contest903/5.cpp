/* E. Block Sequence */

/* https://codeforces.com/contest/1881/problem/E */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

/* Recursion + Memorization */

int f(int index, int n, vi &vec, vi &dp)
{
    // cout << "Hello" << endl;

    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int deleted = 1 + f(index + 1, n, vec, dp);

    int not_deleted = 1e9;

    if (n - index - 1 >= vec[index])
        not_deleted = 0 + f(index + vec[index] + 1, n, vec, dp);

    return dp[index] = min(deleted, not_deleted);
}

void solve()
{
    int n;
    cin >> n;

    vi vec(n);

    for (auto &i : vec)
        cin >> i;

    vi dp(n, -1);

    int answer = f(0, n, vec, dp);

    cout << answer << endl;
}

/* Tabulation */

void solve()
{
    int n;
    cin >> n;

    vi vec(n);

    for (auto &i : vec)
        cin >> i;

    vi dp(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        int deleted = 1 + dp[index + 1];

        int not_deleted = 1e9;

        if (n - index - 1 >= vec[index])
            not_deleted = 0 + dp[index + vec[index] + 1];

        dp[index] = min(deleted, not_deleted);
    }

    cout << dp[0] << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}