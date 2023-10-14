/* https://codeforces.com/contest/1867/problem/B */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, mismatch = 0, flag = 0;
    cin >> n;

    string s, res = "";
    cin >> s;

    for (ll i = 0; i < n / 2; i++)
        mismatch += s[i] != s[n - i - 1];

    for (ll i = 0; i < mismatch; i++)
        res += '0';

    if (n & 1)
    {
        for (ll i = mismatch; i <= (n - mismatch); i++)
            res += '1';
    }
    else
    {
        for (ll i = mismatch; i <= (n - mismatch); i++)
        {
            res += flag % 2 == 0 ? '1' : '0';
            flag++;
        }
    }
    for (ll i = 0; i < mismatch; i++)
        res += '0';

    cout << res << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}