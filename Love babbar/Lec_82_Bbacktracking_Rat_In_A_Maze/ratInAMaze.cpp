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

void solve(vector<vector<int>> &arr, vector<vector<int>> &map, int i, int j, string str, vector<string> &ans, int n)
{
    if ((i == n - 1) and (j == n - 1))
    {
        ans.push_back(str);
        return;
    }
    if ((i >= n or j >= n) or (i < 0 or j < 0) or arr[i][j] == 0)
        return;

    if (map[i][j] == 1)
        return;

    for (int path = 0; path < 4; path++)
    {
        char ch = paths[path];
        map[i][j] = 1;
        str.push_back(paths[path]);

        switch (paths[path])
        {
        case 'D':
            if (isSafe(arr, map, i + 1, j, n))
                solve(arr, map, i + 1, j, str, ans, n);
            break;
        case 'L':
            if (isSafe(arr, map, i, j - 1, n))
                solve(arr, map, i, j - 1, str, ans, n);
            break;
        case 'R':
            //                 if(isSafe(arr, map, i, j + 1, n))
            solve(arr, map, i, j + 1, str, ans, n);
            break;
        case 'U':
            //                 if(isSafe(arr, map, i - 1, j, n))
            solve(arr, map, i - 1, j, str, ans, n);
            break;
        }

        str.pop_back();
        map[i][j] = 0;
    }

    /*
    str.push_back('D');
    map[i][j] = 1;
    solve(arr, map, i + 1, j, str, ans, n);
    str.pop_back();
    map[i][j] = 0;

    str.push_back('L');
    map[i][j] = 1;
    solve(arr, map, i, j - 1, str, ans, n);
    str.pop_back();
    map[i][j] = 0;

    str.push_back('R');
    map[i][j] = 1;
    solve(arr, map, i, j + 1, str, ans, n);
    str.pop_back();
    map[i][j] = 0;

    str.push_back('U');
    map[i][j] = 1;
    solve(arr, map, i - 1, j, str, ans, n);
    str.pop_back();
    map[i][j] = 0;
    */
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<int>> map(n, vector<int>(n, 0));
    string str = "";
    solve(arr, map, 0, 0, str, ans, n);

    return ans;
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

    vector<string> ans = searchMaze(arr, n);

    for (auto str : ans)
        cout << str << endl;

    return 0;
}