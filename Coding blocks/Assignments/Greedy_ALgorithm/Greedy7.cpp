/////////// Dividing an array

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
Here After sorting 
In minimum difference :- The adjacent number will have the minimum difference
In maximum difference :- When (i)th and (n-i)th elements are subtracted the difference will be the maximum
*/

int main()
{
    ll t, n, ele;
    cin >> t;
    vector<ll> v1;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> ele;
            v1.push_back(ele);
        }
        ll mn = 0, mx = 0;
        sort(v1.begin(), v1.end());

        for (ll i = 0; i < n; i += 2)
        {
            mn += v1[i + 1] - v1[i];
        }
        for (ll i = 0; i < n / 2; i++)
        {
            mx += v1[n - i - 1] - v1[i];
        }
        cout << mn << " " << mx << endl;
    }

    return 0;
}