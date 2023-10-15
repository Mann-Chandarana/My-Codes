/* Labyrinth */

/* https://cses.fi/problemset/task/1193 */

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

pi source, destination;

vi dirx = {-1, 0, 1, 0};
vi diry = {0, -1, 0, 1};

bool valid(int x, int y, int n, int m, vvc &mat)
{
    if (x >= 0 and x < n and y >= 0 and y < m and (mat[x][y] == '.' || mat[x][y] == 'B'))
        return true;
    return false;
}

string find_path(vvc &mat, int x, int y, int n, int m, string &answer)
{
    if (x == destination.first and y == destination.second)
        return answer;

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (valid(newx, newy, n, m, mat))
        {
            mat[newx][newy] = '#';

            if (i == 0)
                answer.pb('U');

            else if (i == 1)
                answer.pb('L');

            else if (i == 2)
                answer.pb('D');

            else
                answer.pb('R');

            if (find_path(mat, newx, newy, n, m, answer) != " ")
                return answer;

            answer.pob();
            mat[newx][newy] = '.';
        }
    }
    return " ";
}

int main()
{
    int n, m;
    cin >> n >> m;

    vvc mat(n, vc(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
                source = {i, j};
            else if (mat[i][j] == 'B')
                destination = {i, j};
        }
    }

    string answer;

    if (find_path(mat, source.first, source.second, n, m, answer) == " ")
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << answer.length() << endl;
        cout << answer << endl;
    }

    return 0;
}