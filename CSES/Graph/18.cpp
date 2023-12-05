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

void dfs(int node, int k, vi adj[], int &answer)
{
    if (k == 0)
    {
        answer = node;
        return;
    }

    for (auto neigh : adj[node])
    {
        k -= 1;
        dfs(neigh, k, adj, answer);
    }
}

int main()
{
    fastread();

    int n, q;
    cin >> n >> q;

    vector<int> adj[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;

        adj[i].pb(t);
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;

        int answer;
        dfs(x, k, adj, answer);

        cout << answer << endl;
    }

    return 0;
}