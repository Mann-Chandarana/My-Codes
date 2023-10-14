#include "bits/stdc++.h"
using namespace std;

// It is used in BST,Triangulations, etc.

// We can get optimized solution with O(N) with the help of Dynamic Programming.
int catalan(int n)
{
    if (n <= 1)
        return 1;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - 1 - i);
    }

    return res;
}

int main()
{

    return 0;
}