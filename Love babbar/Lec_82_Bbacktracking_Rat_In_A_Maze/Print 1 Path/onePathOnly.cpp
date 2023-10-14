#include <bits/stdc++.h>
using namespace std;

char paths[4] = {'D', 'L', 'R', 'U'};

bool isSafe(vector<vector<int>> &arr, vector<vector<int>> &map, int i, int j, int n)
{
    if ((i >= n or j >= n) or (i < 0 or j < 0))
        return false;

    if (arr[i][j] == 0)
        return false;

    if (map[i][j] == 1)
        return false;

    return true;
}

bool solve(vector<vector<int>> &arr, vector<vector<int>> &map, int i, int j, string &str, int n)
{
    if ((i == n - 1) and (j == n - 1))
    {
        return true;
    }
    if ((i >= n or j >= n) or (i < 0 or j < 0) or arr[i][j] == 0)
        return false;

    if (map[i][j] == 1)
        return false;

    for (int path = 0; path < 4; path++)
    {
        char ch = paths[path];
        map[i][j] = 1;
        str.push_back(paths[path]);

        switch (paths[path])
        {
        case 'D':
            if (isSafe(arr, map, i + 1, j, n))
                if (solve(arr, map, i + 1, j, str, n) == true)
                    return true;
            break;
        case 'L':
            if (isSafe(arr, map, i, j - 1, n))
                if (solve(arr, map, i, j - 1, str, n))
                    return true;
            break;
        case 'R':
            // if (isSafe(arr, map, i, j + 1, n))
            if (solve(arr, map, i, j + 1, str, n) == true)
                return true;
            break;
        case 'U':
            // if (isSafe(arr, map, i - 1, j, n))
            if (solve(arr, map, i - 1, j, str, n))
                return true;
            break;
        }

        str.pop_back();
        map[i][j] = 0;
    }

    return false;
}

void searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<int>> map(n, vector<int>(n, 0));
    string str = "";
    if (solve(arr, map, 0, 0, str, n))
        cout << str << endl;
    else
        cout << "Cannot find a way" << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // 1 represents path and 0 represents block

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    searchMaze(arr, n);

    return 0;
}