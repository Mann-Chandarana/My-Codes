// Exist or not

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
    int t;
    cin >> t;
    ll n, no, q;

    while (t--)
    {
        cin >> n;
        unordered_map<ll, ll> mp1;
        for (ll i = 0; i < n; i++)
        {
            cin >> no;
            mp1[no]++;
        }
        cin >> q;
        while (q--)
        {
            cin >> no;
            if (mp1[no] > 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}