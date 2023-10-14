////////// Connect two island

#include <bits/stdc++.h>
using namespace std;

int row[] = {-1, -1, -1, 0, 1, 0, 1, 1};
int col[] = {-1, 1, 0, -1, -1, 1, 0, 1};

bool isSafe(int i, int j, vector<vector<int>> mat)
{
    if ((i >= 0 && i < mat.size()) && (j >= 0 && j < mat[0].size()))
    {
        return true;
    }
    return false;
}

int DFS(vector<vector<int>> mat, int i, int j, int path)
{
    cout << "Hello" << endl;
    static int MINI = INT_MAX;
    if (mat[i][j] == 1)
    {
        return path;
    }
    for (int k = 0; k < 8; k++)
    {
        if (isSafe(i + row[k], j + col[k], mat))
        {
            path += DFS(mat, i + row[k], j + col[j], path + 1);
        }
        MINI = min(path, MINI);
    }
    return MINI;
}

int connect_two_island(vector<vector<int>> mat)
{
    if (mat.size() == 0)
    {
        return 0;
    }

    int N = mat.size();
    int M = mat[0].size();

    int count = 0;
    int Mini = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j])
            {
                count = DFS(mat, i + row[k], j + col[k], 1);
                Mini = min(count, Mini);
            }
        }
    }
    cout << Mini << endl;

    return Mini;
}

int main()
{
    int n, m, ele;
    cin >> n >> m;

    vector<vector<int>> vec1(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ele;
            vec1[i].push_back(ele);
        }
    }

    cout << connect_two_island(vec1) << endl;

    return 0;
}