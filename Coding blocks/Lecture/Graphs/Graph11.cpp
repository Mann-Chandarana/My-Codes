/////////// Cycle detection in undirected graph using bfs

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

bool check(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
{
    queue<int> q;
    visited[node] = 1;
    parent[node] = -1;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto ele : adj[frontNode])
        {
            if (visited[ele] and parent[frontNode] != ele)
            {
                // cout << node << " " << frontNode << " " << parent[frontNode] << " " << ele << endl;
                return true;
            }

            if (!visited[ele])
            {
                visited[ele] = 1;
                parent[ele] = frontNode;
                q.push(ele);
            }
        }
    }

    return false;
}

bool cyclePresent(vpii edges, int v, int e)
{
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create visited DS and parent DS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // Checks for each components of the graph
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (check(i, adj, visited, parent))
                return true;
        }
    }

    return false;
}

int main()
{
    int v;
    cout << "Enter number of vertexes: ";
    cin >> v;
    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int, int>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;

        edges.push_back(make_pair(u, v));
    }

    if (cyclePresent(edges, v, e))
        cout << "Yes cycle is present\n";
    else
        cout << "Cycle is not present\n";

    return 0;
}