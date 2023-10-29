/* Round Trip II */

/* https://cses.fi/problemset/task/1678/ */

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

bool dfs(int node, vi &visited, vi &pathVisited, vi &answer, vi adj[])
{
    visited[node] = true;
    pathVisited[node] = true;
    answer.pb(node);

    for (auto neigh : adj[node])
    {
        if (!visited[neigh])
        {
            if (dfs(neigh, visited, pathVisited, answer, adj))
                return true;
        }
        else
        {
            if (pathVisited[neigh])
            {
                answer.pb(neigh);
                return true;
            }
        }
    }
    pathVisited[node] = false;
    answer.pob();

    return false;
}

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
    }

    bool canFindCycle = false;
    vi visited(n + 1, false), pathVisited(n + 1, false), subAnswer;

    for (int i = 1; i <= n; i++)
    {
        if (dfs(i, visited, pathVisited, subAnswer, adj))
        {
            canFindCycle = true;
            break;
        }
    }

    if (canFindCycle)
    {
        vi answer;

        int CycleStarting = subAnswer[subAnswer.size() - 1];
        bool canPrint = false;

        for (auto element : subAnswer)
        {
            if (element == CycleStarting)
                canPrint = true;

            if (canPrint)
                answer.pb(element);
        }

        cout << answer.size() << endl;
        for (auto element : answer)
            cout << element << " ";

        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}