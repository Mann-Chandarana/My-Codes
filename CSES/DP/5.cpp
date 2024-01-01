/* Removing Digits */

/* https://cses.fi/problemset/task/1637 */

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

/*** Recursion + Memorization ***/

int solve(int n, vi &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    string str = to_string(n);

    int answer = INT_MAX;

    for (int i = 0; i < str.length(); i++)
    {
        int num = str[i] - '0';
        if (num != 0 and num <= n)
            answer = min(answer, 1 + solve(n - num, dp));
    }

    return dp[n] = answer;
}

int main()
{
    fastread();

    int n;
    cin >> n;

    vi dp(n + 1, -1);

    cout << solve1(n) << endl;
    return 0;
}