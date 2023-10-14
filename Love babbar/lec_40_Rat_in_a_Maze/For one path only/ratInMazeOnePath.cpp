// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

bool ratInMaze(vector<vector<int>> &maze, vector<vector<int>> &visited, int row, int col, string &path)
{
    if ((col < 0 or col >= maze[0].size()) or (row < 0 or row >= maze.size()) or (maze[row][col] == 0) or (visited[row][col] == 1) or (col < 0 or col >= maze[0].size()))
    {
        return false;
    }

    if ((row == maze.size() - 1) and (col == maze[0].size() - 1))
    {
        return true;
    }

    visited[row][col] = 1;

    // Down
    path.push_back('D');
    if (ratInMaze(maze, visited, row + 1, col, path) == true)
    {
        return true;
    }
    path.pop_back();

    // Right
    path.push_back('R');
    if (ratInMaze(maze, visited, row, col + 1, path) == true)
    {
        return true;
    }
    path.pop_back();

    // Left
    path.push_back('L');
    if (ratInMaze(maze, visited, row, col - 1, path) == true)
    {
        return true;
    }
    path.pop_back();

    // Up
    path.push_back('U');
    if (ratInMaze(maze, visited, row - 1, col, path) == true)
    {
        return true;
    }
    path.pop_back();

    visited[row][col] = 0;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m, 0)), visited(n, vector<int>(m, 0));
    int row = 0, col = 0;
    string path = "";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    if (ratInMaze(maze, visited, row, col, path) == true)
    {
        cout << path << endl;
    }
    else
    {
        cout << "Cannot find a path" << endl;
    }

    cout << "\nMain end\n";
    return 0;
}
