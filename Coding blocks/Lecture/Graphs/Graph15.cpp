//////////// Shortest distance in undirected graph

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adj;

public:
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> shortestPath(int src, int des)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> parent;
        queue<int> q;

        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty())
        {
            int Node = q.front();
            q.pop();

            for (auto neighbour : adj[src])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = Node;
                }
            }
        }

        vector<int> ans;
        int currentans = des;

        while (currentans != -1)
        {
            ans.push_back(currentans);
            currentans = parent[currentans];
        }
        return ans;
    }
};

int main()
{

    return 0;
}