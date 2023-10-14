#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<pair<int, int>>> adj;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int wt)
    {
        adj[x - 1].push_back(make_pair(y - 1, wt));
        adj[y - 1].push_back(make_pair(x - 1, wt));
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

        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else if (distance[i] != 0)
            {
                cout << distance[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    int t, N, M;
    cin >> t;

    while (t--)
    {
        cin >> N >> M;
        Graph g(N);
        int x, y, wt;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y >> wt;
            g.addEdge(x, y, wt);
        }
        int src;
        cin >> src;
        g.dijkstra(src - 1);
    }

    return 0;
}