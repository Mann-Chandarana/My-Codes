/* Coin Combinations II */

/* https://cses.fi/problemset/task/1636/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

const int mod = 1e9 + 7;

/*** Recursion + Memorization ***/

int solve(int index, int x, int n, vi &coins, vector<vector<int>> &dp)
{
    if (x == 0)
        return 1;

    if (index >= n)
        return 0;

    if (dp[index][x] != -1)
        return dp[index][x];

    ll picking = 0, not_picking = 0;

    if (x >= coins[index])
        picking = solve(index, x - coins[index], n, coins, dp) % mod;

    not_picking = solve(index + 1, x, n, coins, dp) % mod;

    return dp[index][x] = (picking + not_picking) % mod;
}

/*** Tabulation ***/

int solve(int x, int n, vi &coins, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            ll picking = 0, not_picking = 0;

            if (sum >= coins[index])
                picking = dp[index][sum - coins[index]] % mod;

            not_picking = dp[index + 1][sum] % mod;

            dp[index][sum] = (picking + not_picking) % mod;
        }
    }
    return dp[0][x];
}

/*** Space Optimization ***/

int solve(int x, int n, vi &coins)
{
    vector<int> next(x + 1, 0);
    vector<int> curr(x + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            curr[0] = 1;
            ll picking = 0, not_picking = 0;

            if (sum >= coins[index])
                picking = curr[sum - coins[index]] % mod;

            not_picking = next[sum] % mod;

            curr[sum] = (picking + not_picking) % mod;
        }
        next = curr;
    }
    return curr[x];
}

int main()
{
    fastread();

    ll n, x;
    cin >> n >> x;

    vi coins(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (auto &i : coins)
        cin >> i;

    cout << solve(x, n, coins) << endl;

    return 0;
}