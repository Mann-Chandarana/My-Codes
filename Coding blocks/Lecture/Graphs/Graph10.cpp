/////////// Cycle detection in undirected graph using dfs

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(T x, T y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool cyclic_helper(int node, vector<bool> &visited, int parent)
    {
        visited[node] = true;

        for (auto nbr : adj[node])
        {
            if (!visited[nbr])
            {
                bool cycle_mila = cyclic_helper(nbr, visited, node);
                if (cycle_mila)
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle()
    {
        vector<bool> visited(V, false);
        return cyclic_helper(0, visited, -1);
    }
};

int main()
{
    Graph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    cout << g.contains_cycle() << endl;
    return 0;
}