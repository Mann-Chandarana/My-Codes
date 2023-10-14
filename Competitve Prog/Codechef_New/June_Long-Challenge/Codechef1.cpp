//////////// GCD and LCM

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ll i = 1, j = 1;
        ll count = 0, ans = 0;

        while (i < n || j < n)
        {
            cout << i << " " << j << endl;
            int Gcd = gcd(i, j);
            int LCM = i * j / (Gcd);
            ans = pow(i, 2) + pow(j, 2) + pow(Gcd, 2) + pow(LCM, 2);

            if (ans == n)
            {
                if (i != j)
                {
                    count += 2;
                }
                else
                {
                    count++;
                }

                i++;
            }
            else if (ans > n)
            {
                i++;
            }

            j++;
        }

        cout << count << endl;
    }

    return 0;
}