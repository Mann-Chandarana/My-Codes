/////////////////// Beautiful vertices

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int, list<int>> adj;

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

    void dfs(int current, int parent, bool *visited, int &ans)
    {
        visited[current] = true;

        for (auto neigh : adj[current])
        {
            if (!visited[neigh])
            {
                dfs(neigh, current, visited, ans);
                int n = adj[current].size();
                if (parent != -1)
                {
                    n--;
                }
                if (adj[neigh].size() - 1 > n)
                {
                    ans++;
                }
            }
        }
    }

    int Beautiful_vertices()
    {
        bool *visited = new bool[V];
        int ans = 0;
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            dfs(i, -1, visited, ans);
        }
        return ans;

        delete[] visited;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Graph g(N);

    int x, y;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        g.addEdge(x - 1, y - 1);
    }

    cout << g.Beautiful_vertices() << endl;

    return 0;
}