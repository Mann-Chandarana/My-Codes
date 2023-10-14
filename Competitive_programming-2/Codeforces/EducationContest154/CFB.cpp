/* https://codeforces.com/contest/1861/problem/B */

/*
Solution :-
1) By observation
if there are two string name a and b
suppose a[i]==0 and a[i+1]==1 and b[i]==0 and b[i+1]==1
then both the string can be make same otherwise it is not possible to make the string equal
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string a, b;
    cin >> a >> b;

    if (a == b)
        cout << "YES" << endl;

    else
    {
        int n = a.length();

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == '0' and b[i] == '0' and a[i + 1] == '1' and b[i + 1] == '1')
            {
                cout << "YES" << endl;
                return;
            }
        }
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