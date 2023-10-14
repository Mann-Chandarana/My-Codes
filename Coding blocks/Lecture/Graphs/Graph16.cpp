//////////// Shortest distance in directed graph 

#include <bits/stdc++.h>
using namespace std;

/* 
1) first do topological sort
2) make distance array
3) and update it according to topological ordering
*/

class Graph
{
    map<int, list<pair<int, int>>> adj;

public:
    void addEdge(int x, int y, int weight)
    {
        pair<int, int> p = make_pair(y, weight);
        adj[x].push_back(p);
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

        for (auto neighour : adj[node])
        {
            if (!visited[neighour.first])
            {
                dfs(neighour.first, visited, order);
            }
        }

        order.push(node);
    }

    void shorttest_path(int src, vector<int> &dist, stack<int> &topo)
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
                    {
                        dist[neighbour.first] = dist[top] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int n = 6;

    unordered_map<int, bool> visited;
    stack<int> order;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, order);
        }
    }

    int src = 1;
    vector<int> dist(n, INT_MAX);

    g.shorttest_path(1, dist, order);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}