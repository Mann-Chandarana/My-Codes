/* Channel :- https://codeforces.com/contest/1863 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, a, q;
    cin >> n >> a >> q;

    string s;
    cin >> s;

    ll left_person = n - a;

    if (left_person == 0)
        cout << "YES" << endl;
    else
    {
        ll count = a, total = a;
        bool check = false;

        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] == '+')
            {
                count++, total++;

                if (count >= n)
                    check = true;
            }
            else
                count--;
        }
        if (total >= n)
        {
            if (check)
                cout << "YES" << endl;

            else
                cout << "MAYBE" << endl;
        }
        else
            cout << "NO" << endl;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}