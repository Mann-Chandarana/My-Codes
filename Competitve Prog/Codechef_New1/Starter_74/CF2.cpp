/* Odd and Even binary String */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; i++)
            cin >> vec[i];

        int no_ones = 0, no_zero = 0;

        for (int i = 0; i < n; i++)
        {
            if (vec[i] == 1) no_ones++;
            else no_zero++;
        }
        bool val = false;
        if (no_ones <= n)
        {
            n -= no_ones;

            if (n % 2 == 0) val = true;
        }

        if (val) cout << "YES" << endl;

        else cout << "NO" << endl;
    }

    return 0;
}