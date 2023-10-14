/////////// 2D magical matrix

#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, -1, -1, 0, 1, 0, 1, 1};
int col[] = {-1, 1, 0, -1, -1, 1, 0, 1};

bool isSafe(int i, int j, vector<vector<int>> mat, vector<vector<int>> visited)
{
    if ((i >= 0 && i < mat.size()) && (j >= 0 && j < mat[0].size()) && mat[i][j] && visited[i][j] == 0)
    {
        return true;
    }
    return false;
}

void BFS(vector<vector<int>> mat, vector<vector<int>> &visited, int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    visited[i][j] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            if (isSafe(x + row[i], y + col[i], mat, visited))
            {
                visited[x + row[i]][y + col[i]] = 1;
                q.push(make_pair(x + row[i], y + col[i]));
            }
        }
    }
}

int count_island(vector<vector<int>> mat)
{
    if (mat.size() == 0)
    {
        return 0;
    }

    int N = mat.size();
    int M = mat[0].size();

    vector<vector<int>> visited(N, vector<int>(M, 0));

    int island = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && mat[i][j])
            {
                BFS(mat, visited, i, j);
                island++;
            }
        }
    }
    return island++;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, ele;
        cin >> n;

        vector<vector<int>> vec1(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ele;
                vec1[i].push_back(ele);
            }
        }
        cout << count_island(vec1) << endl;
    }

    return 0;
}
