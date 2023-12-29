/* Dice Combinations */

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

int mod = 1e9 + 7;

/* Recurion + Memorization */

int solve(int n, vector<ll> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll solution = 0;
    for (ll i = 1; i <= 6; i++)
        if (i <= n)
            solution += solve(n - i, dp), solution %= mod;

    return dp[n] = solution;
}

/* Tabulation */

int main()
{
    fastread();
    ll n;
    cin >> n;

    vector<ll> dp(n + 1, -1);

    dp[0] = 1;
    for (int l = 1; l <= n; l++)
    {
        ll solution = 0;
        for (ll i = 1; i <= 6; i++)
            if (i <= l)
                solution += dp[l - i], solution %= mod;
        dp[l] = solution;
    }
    cout << dp[n] << endl;

    return 0;
}