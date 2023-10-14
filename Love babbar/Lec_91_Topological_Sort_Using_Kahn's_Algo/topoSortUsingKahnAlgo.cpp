#include <bits/stdc++.h>
using namespace std;

// Kahn's algo: Topological sort using BFS.
// Question: https://www.codingninjas.com/codestudio/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

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

vi topoUsingBFS(vpii edges, int v, int e)
{
    // Create an adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Create Indegree DS
    vi indegree(v);
    for (auto row : adj)
    {
        for (auto ele : row.second)
        {
            // edge (u->v) means v has one indegree
            indegree[ele]++;
        }
    }

    // Push all elements with 0 indegree to queue
    queue<int> q;
    for (int i = 0; i < v; i++)
        if (indegree[i] == 0)
            q.push(i);

    // Do BFS
    vi ans;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            // Decrease the indegree of all neighbour node and if indegree becomes 0 push the node to queue
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

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

    vi topo = topoUsingBFS(edges, v, e);

    printArr(topo, topo.size());

    return 0;
}