/* https://practice.geeksforgeeks.org/problems/coin-change2448/1 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/****** Recursion + Memorization ******/

lli solve(int i, int sum, int coins[], int N, vector<vector<lli>> &dp)
{
    if (sum == 0)
        return 1;

    if (i == N)
        return 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    lli not_take = solve(i + 1, sum, coins, N, dp);

    lli take = 0;
    if (coins[i] <= sum)
        take = solve(i, sum - coins[i], coins, N, dp);

    return dp[i][sum] = take + not_take;
}

long long int count(int coins[], int N, int sum)
{
    vector<vector<lli>> dp(N, vector<lli>(sum + 1, -1));
    return solve(0, sum, coins, N, dp);
}

/****** Tabulation ******/

long long int count(int coins[], int N, int sum)
{
    vector<vector<lli>> dp(N + 1, vector<lli>(sum + 1, 0));

    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int amt = 0; amt <= sum; amt++)
        {
            lli not_take = dp[i + 1][amt];

            lli take = 0;
            if (coins[i] <= amt)
                take = dp[i][amt - coins[i]];

            dp[i][amt] = take + not_take;
        }
    }
    return dp[0][sum];
}

/****** Space Optimization ******/

long long int count(int coins[], int N, int sum)
{
    vector<lli> curr(sum + 1, 0);
    vector<lli> next(sum + 1, 0);

    for (int i = 0; i <= N; i++)
        next[0] = 1;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int amt = 0; amt <= sum; amt++)
        {
            lli not_take = next[amt];

            lli take = 0;
            if (coins[i] <= amt)
                take = curr[amt - coins[i]];

            curr[amt] = take + not_take;
        }
        next = curr;
    }
    return next[sum];
}

int main()
{
    return 0;
}