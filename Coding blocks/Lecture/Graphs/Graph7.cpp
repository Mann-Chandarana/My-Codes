//////////////// Topological sort using DFS

////// Topological sort is only applicable on directed acyclic graph

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adj;

public:
    void addEdge(T x, T y)
    {
        adj[x].push_back(y);/// Unidirectional
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        // go to all the neighbour of the node that is not visited
        for (T nbr : adj[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited,ordering);
            }
        }

        // at this point
        ordering.push_front(src);
        return;
    }

    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;

        for (auto p : adj)
        {
            T node = p.first;
            visited[node] = false;
        }

        // Iterate over all the vertices and init a dfs call
        for (auto p : adj)
        {
            T node = p.first;

            if (!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }

        for (auto node : ordering)
        {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Python","Datapreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("Datapreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecogn");
    g.addEdge("Dataset","FaceRecogn");

    g.dfs();

    return 0;
}