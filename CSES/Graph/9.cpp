/* Shortest Routes II */

/* https://cses.fi/problemset/task/1672/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();
    int n, m, q;
    cin >> n >> m >> q;

    vector<vll> adjaceny_matrix(n + 1, vll(n + 1, 1000000000000));

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adjaceny_matrix[a][b] = min(adjaceny_matrix[a][b], c);
        adjaceny_matrix[b][a] = min(adjaceny_matrix[b][a], c);
    }

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            if (i == j)
                adjaceny_matrix[i][j] = 0;
        }
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
                adjaceny_matrix[i][j] = min(adjaceny_matrix[i][j], (adjaceny_matrix[i][k] + adjaceny_matrix[k][j]));
        }
    }

    while (q--)
    {
        ll cityA, cityB;
        cin >> cityA >> cityB;

        if (adjaceny_matrix[cityA][cityB] < 1000000000000)
            cout << adjaceny_matrix[cityA][cityB] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}