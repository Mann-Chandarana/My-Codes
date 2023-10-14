//////////////// Prim 's algorithm

#include <bits/stdc++.h>
using namespace std;

/*
Term
----

MST Set = []
Active edge = edge from vertex in MST set to V
MST edge = an edge that has been included in MST so far
*/

//// Algorithm
/* 
1) Start from any source vertex
2) Out of all the vertex edges, pick the one with the smallest weight 
   - select Y in MST
   - add edge starting from Y in the active edge list 
*/
class Graph
{
    /// Adjacency list
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // Most important stuff
        // Int a Min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // another array
        // visited array that denotes whether a node has been included in MST or Not
        bool *visited = new bool[V]{0};
        int ans = 0;

        // begin
        Q.push(make_pair(0, 0)); // weight,node
        while (!Q.empty())
        {
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (visited[to])
            {
                ///// Discard the edge and continue
                continue;
            }

            // otherwise take the current edge
            ans += weight;
            visited[to] = 1;

            // Add the new edge in the queue
            for (auto x : l[to])
            {
                if (visited[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}