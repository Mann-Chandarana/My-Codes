#include <bits/stdc++.h>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for(int i=0;i<n;i++)cout << arr[i] << " "; cout << endl;
*/
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>
#define vpii vector<pair<int, int>>

void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vi &component)
{
    component.push_back(node);
    visited[node] = 1;

    for (auto ele : adj[node])
    {
        if (!visited[ele])
        {
            dfs(ele, adj, visited, component);
        }
    }
}

void adjPrint(unordered_map<int, list<int>> adj)
{
    for (auto row : adj)
    {
        cout << row.first << "-> ";
        for (auto ele : row.second)
            cout << ele << " ";
        cout << endl;
    }
}

vvi dfsInGraph(int V, int E, vpii &edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vvi ans;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // adjPrint(adj);

    for (int i = 0; i < V; i++)
    {

        if (!visited[i])
        {
            vi component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of vertexes: ";
    cin >> n;
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

    vvi dfs = dfsInGraph(n, e, edges);

    for (auto row : dfs)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }

    cout << "Test\n";
    return 0;
}