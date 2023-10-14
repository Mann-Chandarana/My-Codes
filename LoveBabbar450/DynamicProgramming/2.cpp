/* https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/******* Recursion + Memorization *******/

int solve(int i, int W, int wt[], int val[], vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (wt[i] <= W)
            return val[i];
        return 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    int not_take = solve(i - 1, W, wt, val, dp);

    int take = INT_MIN;

    if (wt[i] <= W)
        take = val[i] + solve(i - 1, W - wt[i], wt, val, dp);

    return dp[i][W] = max(take, not_take);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return solve(n - 1, W, wt, val, dp);
}

/******* Tabulation *******/

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++)
    {
        if (wt[0] <= w)
            dp[0][w] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int not_take = dp[i - 1][w];

            int take = INT_MIN;

            if (wt[i] <= w)
                take = val[i] + dp[i - 1][w - wt[i]];

            dp[i][w] = max(not_take, take);
        }
    }
    return dp[n - 1][W];
}

/******* Space optimization *******/

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int>curr(W + 1, 0);
    vector<int>prev(W + 1, 0);

    for (int w = 0; w <= W; w++)
    {
        if (wt[0] <= w)
            prev[w] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int not_take = prev[w];

            int take = INT_MIN;

            if (wt[i] <= w)
                take = val[i] + prev[w - wt[i]];

            curr[w] = max(not_take, take);
        }
        prev = curr;
    }
    return prev[W];
}

int main()
{
    return 0;
}