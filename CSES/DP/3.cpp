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

int sum(int n, int x, vi &coins, vector<ll> &dp)
{
    if (x == 0)
        return 1;

    if (dp[x] != -1)
        return dp[x];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= x)
            ans += sum(n, x - coins[i], coins, dp), ans %= mod;
    }
    return dp[x] = ans;
}

/*** Tabulation ***/

int sum(int n, int x, vi &coins, vector<ll> &dp)
{
    dp[0] = 1;

    for (int weight = 1; weight <= x; weight++)
    {
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= weight)
                ans += dp[weight - coins[i]], ans %= mod;
        }
        dp[weight] = ans;
    }

    return dp[x];
}

int main()
{
    fastread();
    ll n, x;
    cin >> n >> x;

    vi coins(n);
    vector<ll> dp(x + 1, -1);

    for (auto &i : coins)
        cin >> i;

    cout << sum(n, x, coins, dp) << endl;
}