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

int solve(int index, int prev, int n, vi &num, int bound, vector<vector<int>> &dp)
{
    if (index < 0)
        return 1;

    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    int answer = 0;

    if (num[index] == 0)
    {
        if (index == n - 1)
        {
            for (int i = 1; i <= bound; i++)
                answer = (answer + solve(index - 1, i, n, num, bound, dp)) % mod;
        }
        else
        {
            for (int i = -1; i <= 1; i++)
            {
                if (prev + i > 0 and prev + i <= bound)
                    answer = (answer + solve(index - 1, prev + i, n, num, bound, dp)) % mod;
            }
        }
    }
    else
    {
        if (prev == -1 or abs(prev - num[index]) <= 1)
            answer = solve(index - 1, num[index], n, num, bound, dp) % mod;
    }
    return dp[index][prev + 1] = answer;
}

/** Tabulation **/

bool valid(int x, int m)
{
    return x >= 1 and x <= m;
}

int solve1(int n, int m, vi &nums)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        if (nums[0] == i || nums[0] == 0)
            dp[0][i] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (nums[index] != 0 and nums[index] != k)
                continue;

            for (int prev = k - 1; prev <= k + 1; prev++)
            {
                if (valid(prev, m))
                    dp[index][k] = (dp[index][k] + dp[index - 1][prev]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[n - 1][i]) % mod;

    return ans;
}

int main()
{
    fastread();

    int n, m;
    cin >> n >> m;
    vi num(n);

    for (auto &i : num)
        cin >> i;

    // vector<vector<int>> dp(n + 1, vector<int>(m + 2, -1));

    // cout << solve(n - 1, -1, n, num, m, dp) << endl;
    cout << solve1(n, num, m) << endl;

    return 0;
}