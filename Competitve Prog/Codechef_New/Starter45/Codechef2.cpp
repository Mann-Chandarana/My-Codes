#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<ll> vec(2 * n);

        ll even = 0, odd = 0;

        for (ll i = 0; i < 2 * n; i++)
        {
            cin >> vec[i];
            if (vec[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if (odd >= even)
        {
            cout << abs(n - even) << endl;
        }
        vector<ll> min(even);
        ll j = 0;
        if (even > odd)
        {
            for (ll i = 0; i < 2 * n; i++)
            {

                if (vec[i] % 2 == 0)
                {
                    ll count = 0;
                    while (vec[i] % 2 == 0)
                    {
                        count++;
                        vec[i] = vec[i] / 2;
                    }
                    min[j++] = count;
                }
            }
            sort(min.begin(), min.end());
            ll ans = 0;
            ll index = abs(n - odd);
            for (ll i = 0; i < even; i++)
            {
                cout << min[i] << " ";
            }
            cout << endl;
            for (ll i = 0; i < index; i++)
            {
                ans += min[i];
            }

            cout << ans << endl;
        }
    }

    return 0;
}