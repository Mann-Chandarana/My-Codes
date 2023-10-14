////////// Celebrity

#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b)
{
    if (M[a][b] == 1)
    {
        return 1;
    }
    return 0;
}

int Celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();

    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount != n)
    {
        return -1;
    }

    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount != n - 1)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec1(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
        }
    }
    if (Celebrity(vec1, n) != -1)
    {
        cout << Celebrity(vec1, n) << endl;
    }
    else
    {
        cout << "No Celebrity" << endl;
    }

    return 0;
}