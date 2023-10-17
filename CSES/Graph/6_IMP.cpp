/* Round Trip */

/* https://cses.fi/problemset/task/1669/ */

/*
Use DFS and find cycle in the graph
*/

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

bool possible = false;

void dfs(int node, int parent, vi graph[], vector<bool> &visited, vi &answer)
{
    if (possible)
        return;
    if (visited[node])
    {
        if (answer.size() > 2 and !possible)
        {
            possible = true;

            vi ans;
            ans.pb(node);

            for (int i = answer.size() - 1; i >= 0; i--)
            {
                ans.pb(answer[i]);
                if (answer[i] == node)
                    break;
            }
            cout << ans.size() << endl;
            reverse(all(ans));
            for (auto element : ans)
                cout << element << " ";

            cout << endl;

            return;
        }
    }

    visited[node] = true;
    answer.pb(node);

    for (auto neigh : graph[node])
    {
        if (neigh == parent)
            continue;

        dfs(neigh, node, graph, visited, answer);
    }
    answer.pop_back();
}

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vi graph[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> answer;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, graph, visited, answer);
            if (possible)
                break;
        }
    }

    if (!possible)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}