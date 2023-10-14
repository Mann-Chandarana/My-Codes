#include <bits/stdc++.h>
using namespace std;

// TC of bfs and dfs is linear

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

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for (auto ele : adj[frontNode])
        {
            if (!visited[ele])
            {
                q.push(ele);
                visited[ele] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ///////////////////////////////////////////////////////////////////////////////////
    // // If you want answer in sorted order for each node. (Not for entire ans vector)
    // for (int i = 0; i < vertex; i++)
    //     adj[i].sort();
    // ///////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
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

    vector<int> ans = BFS(n, edges);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}