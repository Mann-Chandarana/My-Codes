// https://cses.fi/problemset/task/1634/

/** Minimizing Coins **/

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

/******* Recursion + Memorization ******/

int solve(vi &vec, int x, int n, vi &dp)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return -1;

    if (dp[x] != -2)
        return dp[x];

    int answer = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int result = solve(vec, x - vec[i], n, dp);

        if (result != -1)
            answer = min(answer, result + 1);
    }

    if (answer == INT_MAX)
        answer = -1;

    return dp[x] = answer;
}

/******* Tabulation ******/

int solve(vi &vec, int x, int n)
{
    vi dp(x + 1, 0);
    dp[0] = 0;

    for (int weight = 1; weight <= x; weight++)
    {
        int answer = 1e9;
        for (int i = 0; i < n; i++)
        {
            int result = -1;

            if (weight - vec[i] >= 0)
                result = dp[weight - vec[i]];

            if (result != -1)
                answer = min(answer, result + 1);
        }
        dp[weight] = answer;
    }

    if (dp[x] == 1e9)
        return -1;

    return dp[x];
}

int main()
{
    fastread();

    int n, x;
    cin >> n >> x;

    vi vec(n);

    for (auto &i : vec)
        cin >> i;

    cout << solve(vec, x, n) << endl;

    return 0;
}