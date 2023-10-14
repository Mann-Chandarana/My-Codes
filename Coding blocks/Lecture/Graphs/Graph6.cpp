//////////////// Connected componets

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

    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (T nbr : adj[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs()
    {
        map<T, bool> visited;

        for (auto p : adj)
        {
            T node = p.first;
            visited[node] = false;
        }

        // Iterate over all the vertices and init a dfs call
        int cnt = 0;
        for (auto p : adj)
        {
            T node = p.first;

            if (!visited[node])
            {
                cout << "Components " << cnt << "--> ";
                dfs_helper(node, visited);
                cnt++;
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    g.dfs();

    return 0;
}