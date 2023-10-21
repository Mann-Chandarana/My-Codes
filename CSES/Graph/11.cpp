/* Flight Discount */

/* https://cses.fi/problemset/task/1195/ */

/* 
  Here we have to take two vector
  1) One for distance
  2) Second one if for discount
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<long long, long long> pll;
typedef pair<long long, pll> plpl;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    ll n, m;
    cin >> n >> m;

    vector<pll> adj[n + 1];

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].pb({b, c});
    }

    ll source = 1;
    vector<ll> disc(n + 1, 1e17);
    vector<ll> distance(n + 1, 1e17);

    disc[source] = distance[source] = 0;

    priority_queue<plpl, vector<plpl>, greater<plpl>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty())
    {
        ll u = pq.top().second.first;
        ll dis = pq.top().first;
        ll f = pq.top().second.second;
        pq.pop();

        if (f == 0)
        {
            if (distance[u] < dis)
                continue;
        }

        if (f == 1)
        {
            if (disc[u] < dis)
                continue;
        }

        for (auto child : adj[u])
        {
            ll v = child.first;
            ll w = child.second;

            if (f == 0)
            {
                if ((dis + w) < distance[v])
                {
                    distance[v] = dis + w;
                    pq.push({distance[v], {v, 0}});
                }
                if ((dis + (w / 2)) < disc[v])
                {
                    disc[v] = (dis + (w / 2));
                    pq.push({disc[v], {v, 1}});
                }
            }
            if (f == 1)
            {
                if ((dis + w) < disc[v])
                {
                    disc[v] = (dis + w);
                    pq.push({disc[v], {v, 1}});
                }
            }
        }
    }

    cout << disc[n] << endl;

    return 0;
}