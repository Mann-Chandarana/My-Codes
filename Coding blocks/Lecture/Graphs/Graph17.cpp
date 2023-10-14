////////////// Dijkstra's algorithm

///// Shortest distance algortihm from a give node in undirected graph

///// time complexity ---> O(E logV)
///// space complexit ---> O(N+E)

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<pair<int, int>>> adj;
    int V;

public:
    Graph(int v)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int v)
    {
        adj[x].push_back(make_pair(y, v));
        adj[y].push_back(make_pair(x, v));
    }

    void dijkstra(int src)
    {
        ///////// Creation of distance array
        vector<int> distance(V, INT_MAX);

        //////// create of a basic set of form (distance,node)
        set<pair<int, int>> st;

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            auto top = *(st.begin());
            int node_dist = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            for (auto neighbour : adj[topNode])
            {
                if (node_dist + neighbour.second < distance[neighbour.first])
                {
                    auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));

                    if (record != st.end())
                    {
                        st.erase(record);
                    }

                    distance[neighbour.first] = node_dist + neighbour.second;
                    st.insert(make_pair(distance[neighbour.first], neighbour.first));
                }
            }
        }
    }
};

int main()
{

    return 0;
}