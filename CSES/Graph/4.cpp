/* Message Route */

/* https://cses.fi/problemset/task/1667/ */

/* Simple BFS */

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

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<bool> visited(n + 1, false);
    vi parent(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }

    if (parent[n] == n)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        vi ans;
        while (parent[n] != n)
        {
            ans.pb(n);
            n = parent[n];
        }
        ans.pb(n);
        cout << ans.size() << endl;
        reverse(all(ans));
        for (auto element : ans)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}