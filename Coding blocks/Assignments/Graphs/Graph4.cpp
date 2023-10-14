/////////////// Shortest path using bfs

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void bfs(int src)
    {
        map<int, int> distance;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            distance[i] = INT_MAX;
        }
        
        q.push(src);
        distance[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (distance[i]==0)
            {
                continue;
            }

            if (distance[i] == INT_MAX)
            {
                cout << -1 << " ";
                continue;
            }
            cout << distance[i]*6 << " ";
        }
        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, u, v, src;
        cin >> n >> m;
        Graph g(n);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g.addEdge(u-1, v-1);
        }
        cin >> src;

        g.bfs(src - 1);
    }

    return 0;
}