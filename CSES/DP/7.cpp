/* Book Shop */
/* https://cses.fi/problemset/result/8072452/ */

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

int solve(int index, int x, int n, vi &books, vi &price, vector<vi> &dp)
{
    if (index < 0 || x == 0)
        return 0;

    int take = INT_MIN;

    if (dp[index][x] != -1)
        return dp[index][x];

    if (price[index] <= x)
        take = books[index] + solve(index - 1, x - price[index], n, books, price, dp);

    int not_take = 0 + solve(index - 1, x, n, books, price, dp);

    return dp[index][x] = max(take, not_take);
}

/** Tabulation **/

int solve1(int x, int n, vi &books, vi &price)
{
    vector<vi> dp(n + 1, vi(x + 1, 0));

    for (int index = 1; index <= n; index++)
    {
        for (int xx = 0; xx <= x; xx++)
        {
            int take = INT_MIN;

            if (price[index - 1] <= xx)
                take = books[index - 1] + dp[index - 1][xx - price[index - 1]];

            int not_take = 0 + dp[index - 1][xx];

            dp[index][xx] = max(take, not_take);
        }
    }
    return dp[n][x];
}

int main()
{
    int n, x;
    cin >> n >> x;

    vi books(n), price(n);

    for (auto &i : price)
        cin >> i;

    for (auto &book : books)
        cin >> book;

    cout << solve1(x, n, books, price) << endl;
    return 0;
}