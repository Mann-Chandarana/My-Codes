//////////// Whether a given grph is a bipartite or not

#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color)
{
    visited[node] = color; // 1 or 2 both means visited

    for (auto nbr : graph[node])
    {
        if (!visited[nbr] == 0)
        {
            int subprob = dfs_helper(graph, nbr, visited, node, 3 - color);
            if (!subprob)
            {
                return false;
            }
        }
        else if (nbr != parent and color == visited[nbr])
        {
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N)
{
    int visited[N] = {0}; // 0-Not visited, 1 - Visited color is 1, 2 - Visited color is 2
    int color = 1;
    int ans = dfs_helper(graph, 0, visited, -1, color);

    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> graph[N];

    while (M--)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (dfs(graph, N))
    {
        cout << "Yes its a bipartite" << endl;
    }
    else
    {
        cout << "Not a bipartite" << endl;
    }

    // BFS or DFS by coloring the nodes at each steps (current node has color 1,nbr should have color 2)

    return 0;
}