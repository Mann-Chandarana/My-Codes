/* Building Roads */

/* https://cses.fi/problemset/task/1666/ */

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

class DSU
{
    int n;
    vector<int> parent, size;

public:
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i, size[i] = 1;
    }

    int find_parent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = find_parent(parent[u]);
    }

    void union_by_Size(int u, int v)
    {
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if (parent_u == parent_v)
            return;

        if (size[parent_u] >= size[parent_v])
            parent[parent_v] = parent_u, size[parent_u] += size[parent_v];

        else
            parent[parent_u] = parent_v, size[parent_v] += size[parent_u];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DSU d(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (d.find_parent(a) != d.find_parent(b))
            d.union_by_Size(a, b);
    }

    vi ans;
    int k = 0;

    for (int i = 1; i <= n; i++)
    {
        if (d.find_parent(i) == i)
            k++, ans.pb(i);
    }

    cout << (k - 1) << endl;

    int range = ans.size();

    for (int i = 0; i < range; i++)
    {
        if (i + 1 < range)
            cout << ans[i] << " " << ans[i + 1] << endl;
    }

    return 0;
}