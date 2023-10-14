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

    void bfs_traversal(int src)
    {
        map<int, bool> visited;

        queue<int> q;
        q.push(src);

        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            visited[node] = true;

            for (auto nbrs : adj[node])
            {
                if (!visited[nbrs])
                {
                    cout << nbrs << endl;
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
};

int main()
{

    return 0;
}