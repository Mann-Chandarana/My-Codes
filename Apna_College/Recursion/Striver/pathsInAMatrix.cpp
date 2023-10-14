#include "bits/stdc++.h"
using namespace std;

void findPaths(vector<vector<int>> arr, int i, int j, string s)
{

    if (i >= arr.size() or j >= arr[0].size())
        return;

    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        cout << s << endl;
        return;
    }

    s += 'D';
    findPaths(arr, i + 1, j, s);
    s.pop_back();

    s += "R";
    findPaths(arr, i, j + 1, s);
    s.pop_back();
}

string dir = "DLRU";
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};

void findPathsWithFourDir(vector<vector<int>> arr, int i, int j, string s, vector<vector<int>> visited)
{
    // We can go up and left also, so up in (0,0) would go to i = -1, which is not a valid index in a matrix.
    if (i >= arr.size() or j >= arr[0].size() or i < 0 or j < 0 or visited[i][j] == 1)
        return;

    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        cout << s << endl;
        // exit(1); // To print single answer.
        return;
    }

    visited[i][j] = 1;

    // s += "D";
    // findPathsWithFourDir(arr, i + 1, j, s, visited);
    // s.pop_back();

    // s += "L";
    // findPathsWithFourDir(arr, i, j - 1, s, visited);
    // s.pop_back();

    // s += "R";
    // findPathsWithFourDir(arr, i, j + 1, s, visited);
    // s.pop_back();

    // s += "U";
    // findPathsWithFourDir(arr, i - 1, j, s, visited);
    // s.pop_back();

    // Optimizing the upper four groups of statements.
    for (int x = 0; x < 4; x++)
    {
        s += dir[x];
        findPathsWithFourDir(arr, i + di[x], j + dj[x], s, visited);
        s.pop_back();
    }

    visited[i][j] = 0;
}

int cnt = 0;

// int totalWays(vector<vector<int>> arr, int i, int j, vector<vector<int>> visited)
// {
//     if (i >= arr.size() or j >= arr[0].size() or i < 0 or j < 0 or visited[i][j] == 1 or arr[i][j] == 0)
//         return 0;

//     if (i == arr.size() - 1 and j == arr[0].size() - 1)
//     {
//         return 1;
//     }

//     visited[i][j] = 1;

//     for (int x = 0; x < 4; x++)
//     {
//         cnt += totalWays(arr, i + di[x], j + dj[x], visited);
//     }

//     visited[i][j] = 0;
//     return cnt;
// }

int main()
{
    /*  Matrix Recursion:
        Find paths to reach end index in a matrix. 
    */
    // You can only go right or down.
    int n = 3, m = 3;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    // findPaths(arr, 0, 0, "");

    // Question: Can go in every four directions. Up, Down, Left, Right.
    // Every index should lie only once.

    // n X m  array, for marking visited index.
    vector<vector<int>> visited(n, vector<int>(m, 0));
    findPathsWithFourDir(arr, 0, 0, "", visited);

    // vector<vector<int>> arr1 = {{1, 0, 1},
    //                             {1, 1, 0},
    //                             {1, 1, 1}};
    // cout << totalWays(arr1, 0, 0, visited) << endl;

    return 0;
}