/* Flight Routes */

/* https://cses.fi/problemset/result/7478894/ */

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
    int n, m, k;
    cin >> n >> m >> k;

    vector<pi> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<vll> distance(n + 1, vll(k, 1e17));

    int source = 1;
    distance[source][0] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll u = pq.top().second;
        ll dis = pq.top().first;
        pq.pop();

        if (distance[u][k - 1] < dis)
            continue;

        for (auto element : adj[u])
        {
            int v = element.first;
            int w = element.second;

            if (distance[v][k - 1] > dis + w)
            {
                distance[v][k - 1] = dis + w;
                pq.push({distance[v][k - 1], v});
                sort(all(distance[v]));
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << distance[n][i] << " ";

    cout << endl;

    return 0;
}