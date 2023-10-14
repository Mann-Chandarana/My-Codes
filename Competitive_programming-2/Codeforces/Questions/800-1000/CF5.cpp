/* https://codeforces.com/problemset/problem/1872/B */

/* B. The Corridor or There and Back Again */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

void solve()
{
    ll n;
    cin >> n;

    vpii vec;

    for (int i = 0; i < n; i++)
    {
        int d, s;
        cin >> d >> s;

        vec.pb({d, s});
    }

    sort(all(vec));

    ll k = LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        ll val = vec[i].first;
        if (!(vec[i].second & 1)) // even
            val += max(((vec[i].second) / 2) - 1, 0);

        else
            val += ((vec[i].second) / 2);

        k = min(k, val);
    }
    cout << k << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}