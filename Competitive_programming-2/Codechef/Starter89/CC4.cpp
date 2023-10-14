/******************* Positive or negative subarray *******************/

/* https://www.codechef.com/problems/POSITNEG */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> B(n);

        for (int i = 0; i < n; i++)
            cin >> B[i];

        if (n == 1)
            cout << 1 << endl;

        else
        {
            ll negative = 0;
            for (int i = 0; i < n; i++)
            {
                if (B[i] < 0)
                {
                    negative += i;
                    negative++;
                }
            }
            ll positive = ((n * (n + 1)) / 2) - negative;
            cout << abs(positive - negative) << endl;
        }
    }

    return 0;
}