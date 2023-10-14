//////////// Is a tree or not

//////////// Tree -> In tree cycle is not present

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

    bool isTree()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        int src = 0;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // pop out one node and visit its neighbour

            for (auto nbr : adj[node])
            {                                ///// Most imp to understand    
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph<int> g(3);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    // g.addEdge(0, 3);

    cout<<g.isTree()<<endl;
    return 0;
}