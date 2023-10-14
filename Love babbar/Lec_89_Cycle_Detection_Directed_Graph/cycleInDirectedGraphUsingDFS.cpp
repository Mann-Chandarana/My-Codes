#include <bits/stdc++.h>
using namespace std;

// TC: O(N + E)

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

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    dfsVisited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (checkCycleDFS(neighbour, visited, dfsVisited, adj))
                return true;
        }

        if (visited[neighbour] and dfsVisited[neighbour])
            return true;
    }

    dfsVisited[node] = 0;
    return false;
}

bool cyclePresent(vpii edges, int v, int e)
{
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited, dfsVisited;

    // Call DFS for all components
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
            if (cycleFound)
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