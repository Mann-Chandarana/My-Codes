#include <bits/stdc++.h>
using namespace std;

// Article: https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph

// This code will print shortest distance for EACH NODE from the source node.

/*
    // Algorithm:
    1) Get the topological order.
    2) Using the topological order update the distance array.
*/

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
*/
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

class Graph
{
public:
    unordered_map<int, list<pii>> adj;

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
    }

    void printAdj()
    {
        for (auto row : adj)
        {
            cout << row.first << " -> ";
            for (auto p : row.second)
            {
                cout << "(" << p.first << "," << p.second << "), ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &order)
    {
        visited[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, order);
            }
        }

        order.push(node);
    }

    void getShortestPath(int src, vi &dist, stack<int> &topo)
    {
        dist[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if (dist[top] != INT_MAX)
            {
                for (auto neighbour : adj[top])
                {
                    if (dist[top] + neighbour.second < dist[neighbour.first])
                        dist[neighbour.first] = dist[top] + neighbour.second;
                }
            }
        }
    }
};

int main()
{
    Graph g;

    // int v;
    // cout << "Enter number of vertexes: ";
    // cin >> v;
    // int e;
    // cout << "Enter number of edges: ";
    // cin >> e;
    // for (int i = 0; i < e; i++)
    // {
    //     int u, v, w;
    //     cout << "Enter first node: ";
    //     cin >> u;
    //     cout << "Enter second node: ";
    //     cin >> v;
    //     cout << "Enter weight: ";
    //     cin >> w;
    //     g.addEdge(u, v, w);
    // }
    // g.printAdj();

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // g.printAdj();

    // Topological order

    // Here total number of nodes are 6
    int n = 6;

    unordered_map<int, bool> visited;
    stack<int> order;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // Adj is already there in the class, so no need to pass adj
            g.dfs(i, visited, order);
        }
    }

    // cout << order.size() << endl;
    // while (!order.empty())
    // {
    //     cout << order.top() << " ";
    //     order.pop();
    // }

    // here we are taking source as node 1
    int src = 1;
    vi dist(n, INT_MAX);

    g.getShortestPath(src, dist, order);

    // Add this point dist array contains shortest distance for each node from the source node

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}