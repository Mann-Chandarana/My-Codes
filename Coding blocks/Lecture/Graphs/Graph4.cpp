////////// Snake and ladder Shortest path using BFS

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> adj;

public:
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }

    int bfs(T src, T dest)
    {
        map<T, bool> dist;
        queue<T> q;

        for (auto node_pair : adj)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (int nbr : adj[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for (auto node_pair : adj)
        {
            T node = node_pair.first;
            int d = dist[node];
            cout << "Node " << node << " Dist from source " << d << endl;
        }

        return dist[dest];
    }
};

int main()
{
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    Graph<int> g;
    for (int i = 0; i < 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36);
    g.bfs(0, 36);

    return 0;
}