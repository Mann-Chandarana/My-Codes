/** Rectangle Cutting **/

/** https://cses.fi/problemset/result/8109775/ **/

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

int solve(int a, int b, vector<vi> &dp)
{
    if (dp[a][b] != -1)
        return dp[a][b];

    if (a == b)
        return 0;

    if (a == 1)
        return b - 1;

    if (b == 1)
        return a - 1;

    /////// Horizontal cut

    int horizontal = INT_MAX, vertical = INT_MAX;

    for (int x = 1; x < a; x++)
        horizontal = min(horizontal, (solve(x, b, dp) + solve(a - x, b, dp) + 1));

    /////// Vertical cut

    for (int v = 1; v < b; v++)
        vertical = min(vertical, solve(a, v, dp) + solve(a, b - v, dp) + 1);

    return dp[a][b] = min(horizontal, vertical);
}

/** Tabulation **/

int solve1(int a, int b)
{
    vector<vi> dp(a + 1, vi(b + 1, 0));

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == j)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= b; i++)
        dp[1][i] = i - 1;

    for (int i = 1; i <= a; i++)
        dp[i][1] = i - 1;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            /////// Horizontal cut

            if (i == j)
                continue;

            int horizontal = INT_MAX, vertical = INT_MAX;

            for (int x = 1; x < i; x++)
                horizontal = min(horizontal, (dp[x][j] + dp[i - x][j]) + 1);

            /////// Vertical cut

            for (int v = 1; v < j; v++)
                vertical = min(vertical, (dp[i][v] + dp[i][j - v]) + 1);

            dp[i][j] = min(horizontal, vertical);
        }
    }
    return dp[a][b];
}

int main()
{
    fastread();

    int a, b;
    cin >> a >> b;

    // vector<vi> dp(a + 1, vi(b + 1, -1));

    cout << solve1(a, b) << endl;

    return 0;
}