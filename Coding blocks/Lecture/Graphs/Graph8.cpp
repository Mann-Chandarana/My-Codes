//////////// Topological sort using BFS Kahn's Algorithm

////// Topological sort is only applicable on directed acyclic graph

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

    void TopologialSort()
    {
        /////// Creating a vector for indgree of all the nodes of the graph
        vector<int> indegree(V,0);

        for (auto neighbours : adj)
        {
            for (auto neigh : neighbours.second)
            {
                indegree[neigh]++;
            }
        }

        queue<T> q;

        ///// Pushing all the elements having indegree zero

        for (auto p : adj)
        {
            if (indegree[p.first] == 0)
            {
                q.push(p.first);
            }
        }

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (auto neighb : adj[node])
            {
                indegree[neighb]--;
                if (indegree[neighb] == 0)
                {
                    q.push(neighb);
                }
            }
        }
    }
};

int main()
{
    Graph<int> g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.TopologialSort();
    return 0;
}