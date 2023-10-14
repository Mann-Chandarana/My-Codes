/* Chef odd */

/* https://www.codechef.com/problems/CHEFODD?tab=submissions */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        bool isTrue = false;
        ll total_odd = 0;
        if (!(n & 1))
            total_odd = n / 2;
        else
            total_odd = n / 2 + 1;

        if (n >= 2 * k)
        {
            int left_odd = total_odd - k;

            if (!(left_odd & 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}