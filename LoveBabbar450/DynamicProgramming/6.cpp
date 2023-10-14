/* Edit Distance */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/*
Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
*/

/****** Recursion + Memorization ******/

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    // Base case

    if (j < 0)
        return i + 1;

    if (i < 0)
        return j + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int B, C, D;

    if (s[i] == t[j])
        return solve(i - 1, j - 1, s, t, dp);

    // For insert
    B = 1 + solve(i, j - 1, s, t, dp);

    // For Remove
    C = 1 + solve(i - 1, j, s, t, dp);

    // For Replace
    D = 1 + solve(i - 1, j - 1, s, t, dp);

    return dp[i][j] = min(B, min(C, D));
}

int editDistance(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n - 1, m - 1, s, t, dp);
}

/****** Tabulation ******/

int editDistance(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        int B, C, D;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                // For insert
                B = 1 + dp[i][j - 1];

                // For Remove
                C = 1 + dp[i - 1][j];

                // For Replace
                D = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(B, min(C, D));
            }
        }
    }

    return dp[n][m];
}

/****** Space Optimization ******/

int editDistance(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        int B, C, D;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1];
            else
            {
                // For insert
                B = 1 + curr[j - 1];

                // For Remove
                C = 1 + prev[j];

                // For Replace
                D = 1 + prev[j - 1];
                curr[j] = min(B, min(C, D));
            }
        }
        prev = curr;
    }

    return prev[m];
}

int main()
{
    return 0;
}