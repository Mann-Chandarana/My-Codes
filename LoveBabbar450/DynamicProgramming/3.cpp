#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/*
C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1
*/

/* Recursion + Memorization */

int solve(int n, int r, vector<vector<int>> &dp)
{
    if (r > n)
        return 0;

    if (r == 0 || r == n)
        return 1;

    if (dp[n][r] != -1)
        return dp[n][r];

    return dp[n][r] = (solve(n - 1, r - 1, dp) + solve(n - 1, r, dp));
}

int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    return solve(n, r, dp);
}

/* Iteration */

int mod = 1000000007;

int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                dp[i][j] = 1;

            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n][r] % mod;
}

/* Space Optimization */

int nCr(int n, int r)
{
    vector<int> curr(r + 1, 0);
    vector<int> prev(r + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                curr[j] = 1;

            else
                curr[j] = (prev[j - 1] + prev[j]) % mod;
        }
        prev = curr;
    }
    return prev[r] % mod;
}

int main()
{
    return 0;
}