/* Shortest Routes I */

/* https://cses.fi/problemset/task/1671/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
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
        ll u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({v, w});
    }

    vll distance(n + 1, LONG_LONG_MAX);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    distance[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll dist = pq.top().first;
        ll v = pq.top().second;
        pq.pop();

        if (distance[v] < dist)
            continue;

        for (auto neigh : adj[v])
        {
            ll node = neigh.first;
            ll wt = neigh.second;

            if (dist + wt < distance[node])
            {
                distance[node] = dist + wt;
                pq.push({distance[node], node});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}