/////////////////  Optimisation union function || rank union

#include <bits/stdc++.h>
using namespace std;

/////////////////// Implementing graph using edge list

class Graph
{
    int V;
    list<pair<int, int>> edge_set;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addedge(int u, int v)
    {
        edge_set.push_back(make_pair(u, v));
    }
    ///// Find function
    int findSet(int i, int parent[])
    {
        /// Base case
        if (parent[i] == -1)
        {
            return i;
        }
        // Path compression optimisation
        return parent[i] = findSet(parent[i], parent);
    }

    //// Union function
    void Union_set(int x, int y, int parent[], int rank[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    bool contain_cycle()
    {
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto edge : edge_set)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            if (s1 != s2)
            {
                Union_set(s1, s2, parent, rank);
            }
            else
            {
                cout << "Same Parents " << s1 << " and " << s2 << endl;
                return true;
            }
        }
        delete[] parent;
        delete[] rank;
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 0);

    cout << g.contain_cycle() << endl;
    return 0;
}