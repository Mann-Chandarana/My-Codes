/* https://codeforces.com/contest/1861/problem/C */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;

    ll len = 0, sorted = 0, unsorted = INT_MAX, f = 0;

    for (ll i = 0; i < (ll)s.size(); i++)
    {
        switch (s[i])
        {
        case '+':
            len++;
            break;
        case '-':
            len--;
            break;
        case '1':
            sorted = len;
            break;
        case '0':
            if (unsorted == INT_MAX)
                unsorted = len;
            break;
        }

        if (sorted > len)
            sorted = len;

        if (len < unsorted)
            unsorted = INT_MAX;

        if ((s[i] == '0' and len == sorted) or (s[i] == '1' and unsorted <= len) or (s[i] == '0' and len < 2))
        {
            f = 1;
            break;
        }
    }
    if (f)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}