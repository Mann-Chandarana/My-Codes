/* Edit Distance */

/* https://cses.fi/problemset/result/8091416/ */

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

/** Recursion + Memorization **/

int solve(int i, int j, int n, int m, string &a, string &b, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;

    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = 0 + solve(i - 1, j - 1, n, m, a, b, dp);

    else
    {
        int add = solve(i, j - 1, n, m, a, b, dp);
        int remove = solve(i - 1, j, n, m, a, b, dp);
        int replace = solve(i - 1, j - 1, n, m, a, b, dp);

        return dp[i][j] = 1 + min(add, min(remove, replace));
    }
}

/** Tabulation **/

int solve1(int n, int m, string &a, string &b)
{
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = j ;

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];

            else
            {
                int add = dp[i][j - 1];
                int remove = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];

                dp[i][j] = 1 + min(add, min(remove, replace));
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve1(n, m, a, b) << endl;

    return 0;
}