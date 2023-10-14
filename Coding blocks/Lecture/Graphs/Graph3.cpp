//////////////// Shortest distance to every node end using bfs traversals in bidirectional graph;

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adj;

public:
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, int> dist;
        queue<T> q;

        for (auto node_pair : adj)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : adj[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for (auto node_pair : adj)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " Dist from source " << d << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.bfs(0);

    return 0;
}