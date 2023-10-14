////////////////////////// Rat in a maze

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n, int m, int **visited, string *arr)
{
    if ((x >= 0 && x < m) && (y >= 0 && y < n) && arr[x][y] == 'O' && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// 5 4
// OXOO
// OOOX
// OOXO
// XOOO
// XXOO

bool rat_int_maze(string *arr, int **visited, int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        visited[i][j] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    visited[i][j] = 1;

    ///// right
    if (isSafe(i, j + 1, n, m, visited, arr))
    {
        if (rat_int_maze(arr, visited, i, j + 1, m, n))
        {
            return true;
        }
    }

    ///// Down
    if (isSafe(i + 1, j, n, m, visited, arr))
    {
        if (rat_int_maze(arr, visited, i + 1, j, m, n))
        {
            return true;
        }
    }

    visited[i][j] = 0;
    return false;
}

int main()
{
    int N, M;
    cin >> M >> N;

    string *maze = new string[M];

    for (int i = 0; i < M; i++)
    {
        cin >> maze[i];
    }

    int **visited = new int *[M];

    for (int i = 0; i < M; i++)
    {
        visited[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }
    if (!rat_int_maze(maze, visited, 0, 0, M, N))
    {
        cout << -1 << endl;
    }

    for (int i = 0; i < M; i++)
    {
        delete[] visited[i];
    }

    delete[] visited;

    return 0;
}