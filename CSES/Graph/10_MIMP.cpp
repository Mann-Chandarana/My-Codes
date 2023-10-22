/* https://cses.fi/problemset/task/1673 */

/* High Score */

/*
   Here we have to use bellman ford algorithm so it can tackle negative edges and negative cycle
   1) Bellman ford algorith find the shortest path but here we have to find the maximum so we have to
      negate the edge weight and then find the answer so it will give us the maximum value
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

const ll INF = 1e17;
const ll NINF = INF * (-1);

void solve(int n, int m)
{
    vector<vll> edges;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, x;
        cin >> a >> b >> x;

        vector<ll> vec = {a, b, (-1) * x};
        edges.pb(vec);
    }

    vector<ll> score(n + 1, INF);
    score[1] = 0;

    for (ll i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];

            if (score[u] == INF)
                continue;

            score[v] = min(score[v], w + score[u]);
            score[v] = max(score[v], NINF);
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (auto it : edges)
        {
            ll u = it[0];
            ll v = it[1];
            ll w = it[2];

            if (score[u] == INF)
                continue;

            score[v] = max(score[v], NINF);

            if (score[u] + w < score[v])
                score[v] = NINF;
        }
    }

    if (n == 1 || score[n] == NINF)
    {
        if (n == 1 and (edges[0][2]) == 1)
            cout << 0 << endl;

        else
            cout << -1 << endl;
    }
    else
        cout << score[n] * (-1) << endl;
}

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    solve(n, m);

    return 0;
}