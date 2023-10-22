/* Cycle Finding */

/* https://cses.fi/problemset/task/1197/ */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vector<vi> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    vector<ll> distance(n + 1, 1e17);
    distance[1] = 0;
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int x;
    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    cout << x << endl;

    if (x == -1)
        cout << "NO" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            x = parent[x];

        vector<int> cycle;

        for (int v = x;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == x and cycle.size() > 1)
                break;
        }

        reverse(all(cycle));

        cout << "YES" << endl;
        for (auto element : cycle)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}