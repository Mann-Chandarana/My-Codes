#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/* P(n, k) = P(n-1, k) + k* P(n-1, k-1) */

int nPr(int n, int r)
{
    vector<vector<int>> P(n + 1, vector<int>(r + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0)
                P[i][j] = 1;

            else
                P[i][j] = P[i - 1][j] + j * (P[i - 1][j - 1]);
        }
    }

    return P[n][r];
}

int main()
{
    cout << nPr(10, 2) << endl;
    return 0;
}