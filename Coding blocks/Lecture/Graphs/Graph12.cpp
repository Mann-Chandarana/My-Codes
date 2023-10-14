/////////// Cycle detection in directed graph using DFS

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
    }

    bool cycle_helper(int node, vector<bool> &visited, vector<bool> &stacke)
    {
        visited[node] = true;
        stacke[node] = true;

        for (auto nbr : adj[node])
        {
            if (stacke[nbr] == true)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool cycle_mila = cycle_helper(nbr, visited, stacke);
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        ////// leave a node
        stacke[node] = false;
        return false;
    }

    bool contains_cycle()
    {
        vector<bool> visited(V, false);
        vector<bool> Stacke(V);
        return cycle_helper(0, visited, Stacke);
    }
};

int main()
{
    Graph<int> g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    cout << g.contains_cycle() << endl;
    return 0;
}