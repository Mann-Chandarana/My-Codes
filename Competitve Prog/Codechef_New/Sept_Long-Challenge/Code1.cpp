#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, ele;
        cin >> n;
        unordered_map<ll, ll> mp;

        for (ll i = 0; i < n; i++)
        {
            cin >> ele;
            mp[ele]++;
        }
        ll ans = 0;

        for (auto element : mp)
        {
            if (element.second > 1)
            {
                ans += ((element.second)*(element.second-1))/2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}