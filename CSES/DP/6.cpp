/* Grid Paths */

/* https://cses.fi/problemset/result/8071782/ */

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

/** Recursion + Memorization **/

int solve(int i, int j, int n, vector<string> &grid, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (grid[i][j] == '*')
        return 0;

    int up = 0, left = 0;

    if (i - 1 >= 0)
        up = (solve(i - 1, j, n, grid, dp) % mod);

    if (j - 1 >= 0)
        left = (solve(i, j - 1, n, grid, dp) % mod);

    return dp[i][j] = ((up + left) % mod);
}

/** Tabulation **/

int solve(int n, vector<string> &grid)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 and j == 0) || grid[i][j] == '*')
                continue;

            int up = 0, left = 0;

            if (i - 1 >= 0)
                up = (dp[i - 1][j] % mod);

            if (j - 1 >= 0)
                left = (dp[i][j - 1] % mod);

            dp[i][j] = ((up + left) % mod);
        }
    }
    return dp[n - 1][n - 1];
}

int solve1(int n, vector<string> &grid)
{
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    curr[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 and j == 0) || grid[i][j] == '*')
                continue;

            int up = 0, left = 0;

            if (i - 1 >= 0)
                up = (prev[j] % mod);

            if (j - 1 >= 0)
                left = (curr[j - 1] % mod);

            curr[j] = ((up + left) % mod);
        }
        prev = curr;
        
    }
    return prev[n - 1];
}

int main()
{
    fastread();

    int n;
    cin >> n;

    vector<string> grid(n);

    for (auto &str : grid)
        cin >> str;

    if (grid[0][0] == '*')
        cout << 0 << endl;
    else
    {
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // cout << solve(n - 1, n - 1, n, grid, dp) << endl;

        cout << solve1(n, grid) << endl;
    }

    return 0;
}