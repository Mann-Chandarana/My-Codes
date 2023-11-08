#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int mod = 1e9 + 7;

/* Pruning step */

void Toposort(int n, vector<int> adj[], vector<int> &indegree)
{
    queue<int> q;

    for (int i = 2; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neigh : adj[node])
        {
            indegree[neigh]--;

            if (indegree[neigh] == 0 and neigh!=1)
                q.push(neigh);
        }
    }
}

int main()
{
    fastread();

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> cnt(n + 1, 0);

    Toposort(n, adj, indegree);

    q.push(1);
    cnt[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            indegree[v]--;
            cnt[v] = cnt[v] + cnt[u];
            cnt[v] %= mod;

            if (indegree[v] == 0)
                q.push(v);
        }
    }

    cout << cnt[n] << endl;

    return 0;
}