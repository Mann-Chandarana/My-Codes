/* Building Teams */

/* https://cses.fi/problemset/task/1668/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

bool possible = true;

void dfs(int u, int parent, vi &teams, vi &visited, vi adj[])
{
    for (auto neigh : adj[u])
    {
        if (neigh != parent)
        {
            if (!visited[neigh])
            {
                teams[neigh] = !teams[u];
                visited[neigh] = true;
                dfs(neigh, u, teams, visited, adj);
            }
            else
            {
                if (teams[u] == teams[neigh])
                    possible = false;
            }
        }
    }
}

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vi adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi teams(n + 1), visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            teams[i] = 1;
            dfs(i, -1, teams, visited, adj);
        }
    }

    if (!possible)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (teams[i] == 1)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }

    return 0;
}