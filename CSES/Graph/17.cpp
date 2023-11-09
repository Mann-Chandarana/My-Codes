/* Investigation */

/* https://cses.fi/problemset/task/1202/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
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

int mod = 1e9 + 7;

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vector<pi> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].pb({b, c});
    }

    vector<ll> dist(n + 1, 1e18), count(n + 1, 0), mini(n + 1, 1e18), maxi(n + 1, -1e18);

    priority_queue<pll, vector<pll>, greater<pll>> q;

    q.push({0, 1});
    dist[1] = 0;
    count[1] = 1;
    mini[1] = 0;
    maxi[1] = 0;

    while (!q.empty())
    {
        ll d = q.top().first;
        ll u = q.top().second;
        q.pop();

        if (d > dist[u])
            continue;

        for (auto element : adj[u])
        {
            ll v = element.first;
            ll c = element.second;

            if (dist[u] + c < dist[v])
            {
                dist[v] = dist[u] + c;
                count[v] = count[u];
                mini[v] = mini[u] + 1;
                maxi[v] = maxi[u] + 1;
                q.push({dist[v], v});
            }
            else if (dist[u] + c == dist[v])
            {
                count[v] += count[u];
                count[v] %= mod;
                maxi[v] = max(maxi[v], maxi[u] + 1);
                mini[v] = min(mini[v], mini[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << count[n] << " " << mini[n] << " " << maxi[n] << endl;

    return 0;
}