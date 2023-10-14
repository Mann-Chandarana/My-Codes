#include <bits/stdc++.h>
using namespace std;

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

// My code
/*
class Graph{
    public:
    map<int, list<int>> adj;
    
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void pushAns(vector < vector < int >> &ans, int n)
    {
//         for(auto edge:adj)
//         {        
//             for(auto ele:edge.second)
//             {
//                 ans[edge.first].push_back(ele);
//             }
//         }
        
        for(int i=0;i<n;i++)
        {
            vector<int> tempAns;
            tempAns.push_back(i);
            
            for(auto ele:adj[i]) tempAns.push_back(ele);
            
            ans.push_back(tempAns);
        }
    }
};

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges)
{
    vector < vector < int >> ans;
    Graph g;
    
//     for(int i=0;i<n;i++)
//     {
//         vector<int> tempAns;
//         tempAns.push_back(i);
//         ans.push_back(tempAns);
//     }
    
    for(int i=0;i<m;i++)
    {
        g.addEdge(edges[i][0], edges[i][1]);
    }
    
    g.pushAns(ans, n);
    
    return ans;
}
*/

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges)
{
    vector<vector<int>> ans(n);
    
    for(int i=0;i<n;i++)
        ans[i].push_back(i);
    
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0], v = edges[i][1];
        
        ans[u].push_back(v);
        ans[v].push_back(u);
        
    }
    
    return ans;
}

int main()
{

    return 0;
}