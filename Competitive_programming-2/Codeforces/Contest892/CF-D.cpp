/* https://codeforces.com/contest/1859/problem/D */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

void solve()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vec;

    for (ll i = 0; i < n; i++)
    {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        vec.push_back({l, b});
    }

    sort(all(vec));

    vector<pair<ll, ll>> merge;

    ll l = -1, r = -1;

    for (auto i : vec)
    {
        if (l == -1)
            l = i.first, r = i.second;

        else
        {
            if (i.first <= r)
                r = max(r, i.second);
            else
            {
                merge.push_back({l, r});
                l = i.first;
                r = i.second;
            }
        }
    }

    merge.push_back({l, r});

    vector<ll> lrr, rrr;
    for (auto i : merge)
    {
        lrr.push_back(i.first);
        rrr.push_back(i.second);
    }

    ll q;
    cin >> q;

    while (q--)
    {
        ll val;
        cin >> val;

        ll ans = val;
        auto it = upper_bound(all(lrr), val);

        if (it == lrr.begin())
        {
            cout << val << " ";
            continue;
        }
        it--;

        ll ind = it - lrr.begin();

        if (rrr[ind] >= val)
            val = rrr[ind];

        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}