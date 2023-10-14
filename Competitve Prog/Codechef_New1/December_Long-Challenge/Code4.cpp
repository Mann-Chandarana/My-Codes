/*Divisible by A_i */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        ll result = vec[0];

        for (ll i = 1; i < n; i++)
        {
            result = __gcd(result, vec[i]);
        }

        for (ll i = 0; i < n; i++)
        {
            cout << vec[i] / result << " ";
        }
        cout << endl;
    }

    return 0;
}