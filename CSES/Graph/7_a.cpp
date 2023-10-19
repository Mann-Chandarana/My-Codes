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

vector<int> dirx = {-1, 1, 0, 0};
vector<int> diry = {0, 0, 1, -1};

bool isValid(int newx, int newy, vector<vc> &mat, int time, vector<vi> &distance)
{
    if (newx >= 0 and newx < mat.size() and newy >= 0 and newy < mat[0].size() and (mat[newx][newy] == '.' || mat[newx][newy] == 'A') and time < distance[newx][newy])
        return true;
    return false;
}

void preProcessingTimeOfMatrix(int n, int m, vector<pi> &monsters, vector<vi> &distance, vector<vc> &mat)
{
    queue<pair<pi, int>> q;

    for (auto element : monsters)
        q.push({{element.first, element.second}, 0});

    while (!q.empty())
    {
        pair<int, int> pos = q.front().first;
        int time = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = pos.first + dirx[i];
            int newy = pos.second + diry[i];

            if (isValid(newx, newy, mat, time, distance))
            {
                distance[newx][newy] = time + 1;
                q.push({{newx, newy}, time + 1});
            }
        }
    }
}

int main()
{
    fastread();
    int n, m;
    cin >> n >> m;

    vector<vc> mat(n, vc(m));
    vector<vi> distance(n, vi(m, INT_MAX));
    vector<pi> monsters;
    int sx, sy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];

            if (mat[i][j] == 'M')
            {
                monsters.pb({i, j});
                distance[i][j] = 0;
            }
            else if (mat[i][j] == 'A')
                sx = i, sy = j;
        }
    }
    preProcessingTimeOfMatrix(n, m, monsters, distance, mat);

    queue<pair<pi, int>> q;
    q.push({{sx, sy}, 0});

    int ex, ey;

    bool possible = false;

    while (!q.empty())
    {
        pi pos = q.front().first;
        int timer = q.front().second;
        q.pop();

        if ((pos.first == 0 || pos.first == n - 1 || pos.second == 0 || pos.second == m - 1))
        {
            ex = pos.first;
            ey = pos.second;
            possible = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newx = pos.first + dirx[i];
            int newy = pos.second + diry[i];

            if (newx >= 0 and newx < n and newy >= 0 and newy < m and mat[newx][newy] == '.' and timer+1 < distance[newx][newy])
            {
                if (i == 0)
                    mat[newx][newy] = 'U';

                else if (i == 1)
                    mat[newx][newy] = 'D';

                else if (i == 2)
                    mat[newx][newy] = 'R';

                else
                    mat[newx][newy] = 'L';
                q.push({{newx, newy}, timer + 1});
            }
        }
    }

    if (possible)
    {
        cout << "YES" << endl;
        string answer;
        while (mat[ex][ey] != 'A')
        {
            answer.pb(mat[ex][ey]);
            if (mat[ex][ey] == 'U')
                ex = ex + 1;

            else if (mat[ex][ey] == 'D')
                ex = ex - 1;

            else if (mat[ex][ey] == 'R')
                ey = ey - 1;
            else
                ey = ey + 1;
        }
        reverse(all(answer));
        cout << answer.length() << endl;
        cout << answer << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}