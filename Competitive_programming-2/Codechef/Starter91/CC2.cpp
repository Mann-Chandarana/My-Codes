/* Odd GCD Permutation */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n & 1)
            cout << -1 << endl;
        else
        {
            while (n > 0)
                cout << n-- << " ";
        }
        cout << endl;
    }

    return 0;
}