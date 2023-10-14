/* https://codeforces.com/contest/1869/problem/B */

/*
Solution :-
Here first of all we have to find the minimum distance from A to major city
then we have to find the minimum distance from B to major city

then we have to add dis1+dis2

and the we have to take minimum with direct distance from A to B

dis = min(disAtB,dis1+dis2)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>

void solve()
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;
    vpll vec;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }

    if (a < k and b < k)
    {
        cout << 0 << endl;
        return;
    }

    ll dis = (abs(vec[a].first - vec[b].first) + abs(vec[a].second - vec[b].second));

    ll dist1 = 1e18, dist2 = 1e18;

    for (int i = 0; i < k; i++)
    {
        dist1 = min(dist1, (abs(vec[a].first - vec[i].first) + abs(vec[a].second - vec[i].second)));
        dist2 = min(dist2, (llabs(vec[b].first - vec[i].first) + llabs(vec[b].second - vec[i].second)));
    }

    cout << min(dis, (dist1 + dist2)) << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}