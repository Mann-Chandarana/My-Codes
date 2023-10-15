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

vi dirx = {-1, 0, 1, 0};
vi diry = {0, -1, 0, 1};

int main()
{
    int n, m;
    cin >> n >> m;

    vvc mat(n, vc(m));
    int sx, sy, dx, dy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
                sx = i, sy = j;
            else if (mat[i][j] == 'B')
                dx = i, dy = j;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pi> q;

    q.push({sx, sy});

    bool reached = false;

    while (!q.empty())
    {
        pi p = q.front();
        q.pop();

        if (p.first == dx and p.second == dy)
        {
            reached = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int newx = p.first + dirx[i];
            int newy = p.second + diry[i];

            if (newx >= 0 and newx < n and newy >= 0 and newy < m and (mat[newx][newy] == '.' || mat[newx][newy] == 'B'))
            {
                if (i == 0)
                    mat[newx][newy] = 'U';

                else if (i == 1)
                    mat[newx][newy] = 'L';

                else if (i == 2)
                    mat[newx][newy] = 'D';

                else
                    mat[newx][newy] = 'R';

                q.push({newx, newy});
            }
        }
    }

    if (reached)
    {
        cout << "YES" << endl;
        string answer;
        while ((dx!=sx or dy!=sy))
        {
            answer.pb(mat[dx][dy]);
            if (mat[dx][dy] == 'U')
                dx = dx + 1;

            else if (mat[dx][dy] == 'D')
                dx = dx - 1;

            else if (mat[dx][dy] == 'L')
                dy = dy + 1;

            else
                dy = dy - 1;
        }
        cout << answer.length() << endl;
        reverse(all(answer));
        cout << answer << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}