/////////////// Snake and ladder

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }

    int Bfs(int src, int dest)
    {
        map<int, int> distance;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            distance[i] = INT_MAX;
        }

        q.push(src);
        distance[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : adj[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
            }
        }

        return distance[dest];
    }
};

int main()
{
    int t, n, l, s;
    cin >> t;

    while (t--)
    {
        cin >> n >> l >> s;
        int board[n] = {0};
        int index, value;
        for (int i = 0; i < l; i++)
        {
            cin >> index >> value;
            board[index - 1] = value - 1;
        }
        for (int i = 0; i < s; i++)
        {
            cin >> index >> value;
            board[index - 1] = value - 1;
        }
        Graph g(n);
        for (int i = 0; i < n; i++)
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                int j = i + dice;
                j += board[j];

                if (j < n)
                {
                    g.addEdge(i, j);
                }
            }
        }
        cout<<g.Bfs(0, n -1)<<endl;
    }

    return 0;
}