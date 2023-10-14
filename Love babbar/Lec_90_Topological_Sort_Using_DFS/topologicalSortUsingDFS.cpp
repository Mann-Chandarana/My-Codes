#include <bits/stdc++.h>
using namespace std;

// We can apply topological sort only on directed acyclic graphs
// What is DAG: Linear ordering of vertices, such that for every edge u-v, u always appears before v in that ordering

// TC: O(N + E) SC: Linear

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for(int i=0;i<n;i++)cout << arr[i] << " "; cout << endl;
*/
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

// If the code gives TLE, try using vector instead of unorderd_map for visited and/or adjacency list
void topoUsingDFS(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &order)
// Here we can use vector<list<int>> ^adj to decrease the runtime
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoUsingDFS(neighbour, adj, visited, order);
        }
    }
    order.push(node);
}

vi topologicalSort(vpii edges, int v, int e)
{
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Create visited map and a stack
    stack<int> order;
    vector<bool> visited(v);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoUsingDFS(i, adj, visited, order);
        }
    }

    while (!order.empty())
    {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
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

    topologicalSort(edges, v, e);

    return 0;
}