#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    int halfSize = (n + 1) / 2;

    // For upper part
    for (int i = 1; i <= halfSize; i++)
    {
        for (int j = 1; j <= halfSize - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "* ";
        cout << endl;
    }

    halfSize = n / 2;
    int count = 1;
    // For lower part
    for (int i = 1; i <= halfSize; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= n - 2 * count; j++)
        {
            cout << "* ";
        }
        cout << endl;
        count++;
    }
    return 0;
}