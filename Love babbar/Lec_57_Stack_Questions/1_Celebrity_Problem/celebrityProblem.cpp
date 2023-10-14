#include <bits/stdc++.h>
using namespace std;

// Every knows a celebrity.
// Celebrity does not know anyone.

// Find if there is any celebrity in the party.

bool knows(vector<vector<int>> &mat, int &a, int &b)
{
    // if(mat[a][b] == 1)
    //     return true;

    // return false;

    return mat[a][b];
}

int celebrity(vector<vector<int>> &mat, int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(mat, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // Check wether the remaining person is a celebrity or not with the 2 conditions.

    // If everyone know him.
    for (int i = 0; i < n; i++)
    {
        if (i != s.top())
        {
            if (mat[i][s.top()] == 0)
                return -1;
        }
    }

    // If he doesn't know anyone.
    for (int i = 0; i < n; i++)
    {
        if (mat[s.top()][i] == 1)
            return -1;
    }

    return s.top();
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << celebrity(mat, n) << endl;

    return 0;
}