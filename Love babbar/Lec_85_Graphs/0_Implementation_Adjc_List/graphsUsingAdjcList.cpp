#include <bits/stdc++.h>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for(int i=0;i<n;i++)cout << arr[i] << " "; cout << endl;
*/
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // Direction = 0 -> Undirected Graph
        // Direction = 1 -> Directed Graph

        // Create an edge from u to v (It would be there in both directed and undirected graphs)
        adj[u].push_back(v);

        // If graph is undriected then we would also get an edge from v to u
        if (!direction)
            adj[v].push_back(u);
    }

    void printGraph()
    {
        for (auto node : adj)
        {
            cout << node.first << " -> ";
            for (auto ele : node.second)
                cout << ele << " ";
            cout << endl;
        }
    }
};

int main()
{
    // // Creating undirected graph
    // Graph ug;
    // ug.addEdge(0,1,0);
    // ug.addEdge(0,4,0);
    // ug.addEdge(1,2,0);
    // ug.addEdge(1,3,0);
    // ug.addEdge(2,3,0);
    // ug.addEdge(3,4,0);
    // ug.printGraph();

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Graph<int> g1;
    Graph<char> g1;

    for (int i = 0; i < m; i++)
    {
        // int u, v;
        char u, v;
        cin >> u >> v;

        // Creating an undirected graph
        g1.addEdge(u, v, 0);
    }

    g1.printGraph();

    return 0;
}