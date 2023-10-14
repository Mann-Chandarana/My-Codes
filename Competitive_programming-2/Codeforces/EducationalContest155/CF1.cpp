/* https://codeforces.com/contest/1879 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<ll, ll>

void solve()
{
    ll n;
    cin >> n;

    vector<pii> vec(n);

    for (ll i = 0; i < n; i++)
    {
        ll s, e;
        cin >> s >> e;

        vec[i] = {s, e};
    }
    ll ps = vec[0].first, pe = vec[0].second;
    bool not_possible = false;

    for (ll i = 1; i < n; i++)
    {
        if (vec[i].first >= ps and vec[i].second >= pe)
            not_possible = true;
    }
    if (not_possible)
        cout << -1 << endl;
    else
        cout << ps << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}