/////////// Cycle detection in directed graph using BFS


#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

bool isCyclePresent(vpii edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // get indegree of each node
    vi indegree(v);

    for (auto row : adj)
    {
        for (auto ele : row.second)
        {
            indegree[ele]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Increase count
        count++;

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // If it was a valid topological order, then count would have been same as number of nodes
    // Only in acyclic directed graph we get the valid topological order
    return !(count == v);
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

    if (isCyclePresent(edges, v, e))
        cout << "Yes cycle is present" << endl;
    else
        cout << "No cycle is not present\n";

    return 0;
}