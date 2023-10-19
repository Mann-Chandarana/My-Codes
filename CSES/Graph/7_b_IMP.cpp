/* IMP :- Multi source BFS */

/* Monsters */

/* https://cses.fi/problemset/task/1194/ */

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

int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, 1, -1};
char go[] = {'U', 'D', 'R', 'L'};

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vector<vc> mat(n, vc(m));
    vector<vi> distance(n, vi(m));

    queue<pi> q;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'M')
                q.push({i, j});
            else if (mat[i][j] == 'A')
                x = i, y = j;
        }
    }
    q.push({x, y});
    distance[x][y] = -1;

    while (!q.empty())
    {
        pi pos = q.front();
        q.pop();

        if (mat[pos.first][pos.second] == 'A' and (pos.first == 0 || pos.first == n - 1 || pos.second == 0 || pos.second == m - 1))
        {
            cout << "YES" << endl;
            string ans;
            int d = distance[pos.first][pos.second];
            while (d != -1)
            {
                ans += go[d];
                pos.first -= fx[d];
                pos.second -= fy[d];
                d = distance[pos.first][pos.second];
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            cout << ans << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int xx = pos.first + fx[i];
            int yy = pos.second + fy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || mat[xx][yy] != '.')
                continue;
            else
            {
                mat[xx][yy] = mat[pos.first][pos.second];
                if (mat[xx][yy] == 'A')
                    distance[xx][yy] = i;
                q.push({xx, yy});
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}