/* Course Schedule */

/* https://cses.fi/problemset/task/1679/ */

/* TopoSort */

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
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> answer, visited(n + 1, false);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        visited[node] = true;
        answer.push_back(node);

        for (auto child : adj[node])
        {
            indegree[child]--;

            if (indegree[child] == 0)
                q.push(child);
        }
    }

    if (answer.size() != n)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (auto element : answer)
            cout << element << " ";

        cout << endl;
    }

    return 0;
}