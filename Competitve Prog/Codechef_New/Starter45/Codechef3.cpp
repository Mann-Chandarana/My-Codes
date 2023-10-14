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
        vector<ll> arr(n);
        ll sum = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sum = sum / (n + 1);

        for (ll i = 0; i < n; i++)
        {
            cout << arr[i] - sum << " ";
        }
        cout << endl;
    }

    return 0;
}