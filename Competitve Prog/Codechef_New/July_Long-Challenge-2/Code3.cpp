// To divide or not to divide 

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ll t, a, b, n;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n;

        if (a==0 || b==0||a % b == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            ll temp_number = n;
            if (n % a != 0)
            {
                temp_number = n + a - (n % a);
            }
            while (true)
            {
                if (temp_number % a == 0 and temp_number % b != 0)
                {
                    break;
                }
                temp_number += a;
            }
            cout << temp_number << endl;
        }
    }

    return 0;
}