/////////// Artiulation Point

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adj;
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

    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &ap, unordered_map<int, list<int>> &adj,
             unordered_map<int, bool> &vis)
    {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (auto nbr : adj[node])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!vis[nbr])
            {
                dfs(nbr, node, timer, disc, low, ap, adj, vis);
                low[node] = min(low[node], low[nbr]);

                // check AP or not

                if ((low[nbr] >= disc[node]) && parent != -1)
                {
                    ap[node] = 1;
                }
                child++;
            }
            else
            {
                // Back edge
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if (parent == -1 and child > 1)
        {
            ap[node] = 1;
        }
    }

    vector<int> contain_bridge()
    {
        int timer = 0;

        //// Discoverable time array
        vector<int> disc(V, -1);

        //// Lowest possible time array
        vector<int> low(V, -1);

        int parent = -1;

        unordered_map<int, bool> vis;

        vector<int> result;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, parent, timer, disc, low, result, adj, vis);
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}