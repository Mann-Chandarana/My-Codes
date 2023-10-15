/* Couting rooms */

/* https://cses.fi/problemset/task/1192 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, -1, 0, 1};

void dfs(int i, int j, vector<vector<char>> &mat)
{
    mat[i][j] = '#';

    for (int k = 0; k < 4; k++)
    {
        int newx = i + dirx[k];
        int newy = j + diry[k];

        if ((newx >= 0 and newx < mat.size()) and (newy >= 0 and newy < mat[0].size()) and (mat[newx][newy] == '.'))
            dfs(newx, newy, mat);
    }
}

int main()
{
    fastread();

    int n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '.')
                q.push({i, j});
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (mat[i][j] == '.')
        {
            count++;
            dfs(i, j, mat);
        }
    }

    cout << count << endl;

    return 0;
}