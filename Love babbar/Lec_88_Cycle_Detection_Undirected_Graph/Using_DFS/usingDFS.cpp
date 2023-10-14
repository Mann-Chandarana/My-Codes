#include <bits/stdc++.h>
using namespace std;

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

bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, adj, visited);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent)
            return true;
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

    // Checks for each components of the graph
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            // Parent of src of each component is taken as -1.
            if (isCyclicDFS(i, -1, adj, visited))
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
        cout << "Yes cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;

    return 0;
}