/* https://codeforces.com/problemset/problem/1879/C */

/* C. Make it Alternating :- 1300 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

ll mod = 998244353;

void solve()
{
    ll n, extras = 0, min_ops = 0, factorial = 1, res = 1;

    string s;
    cin >> s;

    n = (ll)(s.size());

    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            extras++;
        else
        {
            min_ops += extras;
            extras++;
            res = ((res % mod) * (extras % mod)) % mod;
            extras = 0;
        }
    }
    if (extras != 0)
    {
        min_ops += extras;
        extras++;
        res = ((res % mod) * (extras % mod)) % mod;
    }

    for (ll i = 1; i <= min_ops; i++)
        factorial = ((factorial % mod) * (i % mod)) % mod;

    res = ((res % mod) * (factorial % mod)) % mod;
    cout << min_ops << " " << res << endl;
}

int main()
{
    fastread();

    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}