#include <bits/stdc++.h>
using namespace std;

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
*/
#define printArr(arr, n)        \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

vi shortestPath(vpii edges, int v, int e, int src, int des)
{
    // Create adjacecny list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create visited DS, parent DS and queue
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(src);
    visited[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }

    vi ans;
    int idx = des;
    // int count = 0;
    while (idx != -1)
    {
        // count++;
        ans.push_back(idx);
        idx = parent[idx];
    }
    // count--;

    // cout << "Number of edges: " << count << endl;

    // The answer vector contains path from destination to source
    reverse(ans.begin(), ans.end());

    return ans;
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

    int src, des;
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> des;

    vi path = shortestPath(edges, v, e, src, des);

    printArr(path, path.size());

    return 0;
}