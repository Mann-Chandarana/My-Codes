//////////// Sum of product 
/*
count number of consecutive one
*/

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> vec(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        ll count = 0, sum = 0;

        for (ll i = 0; i < n; i++)
        {
            if (vec[i] == 0)
            {
                count = 0;
                continue;
            }
            count += 1;
            sum += count;
        }
        cout << sum << endl;
    }

    return 0;
}