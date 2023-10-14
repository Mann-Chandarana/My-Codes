/* https://codeforces.com/contest/1864/problem/A */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define ll long long

void solve()
{
    ll x, y, n;
    cin >> x >> y >> n;

    vector<ll> answer;

    ll diff = 1;

    for (ll i = 0; i < n; i++)
    {
        answer.push_back(y);
        y -= diff;
        diff++;
    }
    if (answer[answer.size() - 1] < x)
        cout << -1 << endl;

    else
    {
        cout << x << " ";

        for (ll i = answer.size() - 2; i >= 0; i--)
            cout << answer[i] << " \n"[i == 0];
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}