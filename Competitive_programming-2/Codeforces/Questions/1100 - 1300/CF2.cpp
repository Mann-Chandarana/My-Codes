/* https://codeforces.com/problemset/problem/1872/D */

/* D. Plus Minus Permutation :- 1200 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

ll range_sum(ll l, ll r)
{
    if (l > r)
        return 0;
    return (((r + l) * 1LL * (r - l + 1)) / 2);
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll common = ((x * 1LL * y) / __gcd(x, y));
    ll no3 = (n / common);

    ll no1 = ((n / x) - no3), no2 = ((n / y) - no3), sum = 0, start = 1;

    cout << range_sum(n - no1 + 1, n) - range_sum(1, no2) << endl;
}

int main()
{
    fastread();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}