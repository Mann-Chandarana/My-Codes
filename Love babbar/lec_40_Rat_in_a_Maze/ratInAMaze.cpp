#include <bits/stdc++.h>
using namespace std;

long long int count = 0;

bool isPossible(vector<vector<int>> &maze, vector<vector<int>> &visited, int row, int col)
{
    if ((row >= 0 and row < maze.size()) and (col >= 0 and col < maze[0].size()) and (visited[row][col] == 0) and (maze[row][col] == 1))
        return true;

    return false;
}

void ratInMaze(vector<vector<int>> &maze, vector<vector<int>> &visited, vector<string> &pathVec, int row, int col, string &path)
{
    if (maze[row][col] == 0)
        return;
    if ((row == maze.size() - 1) and (col == maze[0].size() - 1) and visited[row][col] == 0)
    {
        (::count)++; // To count total possible ways.
        cout << path << endl;
        return;
    }

    visited[row][col] = 1;

    // Down
    if (isPossible(maze, visited, row + 1, col))
    {
        path.push_back('D');
        ratInMaze(maze, visited, pathVec, row + 1, col, path);
        path.pop_back();
    }

    // Left
    if (isPossible(maze, visited, row, col - 1))
    {
        path.push_back('L');
        ratInMaze(maze, visited, pathVec, row, col - 1, path);
        path.pop_back();
    }

    // Right
    if (isPossible(maze, visited, row, col + 1))
    {
        path.push_back('R');
        ratInMaze(maze, visited, pathVec, row, col + 1, path);
        path.pop_back();
    }

    // Up
    if (isPossible(maze, visited, row - 1, col))
    {
        path.push_back('U');
        ratInMaze(maze, visited, pathVec, row - 1, col, path);
        path.pop_back();
    }

    visited[row][col] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }

    int row = 0, col = 0;
    string path = "";
    vector<string> pathVec;
    ratInMaze(maze, visited, pathVec, row, col, path);

    for (auto s : pathVec)
        cout << s << endl;

    cout << ::count << endl;
    cout << "Main end.." << endl;
    return 0;
}