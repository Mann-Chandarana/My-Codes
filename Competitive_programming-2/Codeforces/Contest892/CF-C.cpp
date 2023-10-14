/* https://codeforces.com/contest/1859/problem/C */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
1) Reversing the digit and index 
   a) first reverse last1 then last2 then last3 ..... then find the maximum of all the values

1 10
2 9 
3 8 
4 7 
5 6 
6 5 
7 4 
8 3 
9 2 
10 1
    
2 10
3 9 
4 8 
5 7
6 6
7 5
8 4
9 3
10 2

3 10
4 9
5 8
6 7
7 6
8 5
9 4
10 3

4 10
5 9
6 8
7 7
8 6
9 5
10 4

5 10
6 9
7 8
8 7
9 6
10 5

6 10
7 9
8 8
9 7
10 6

7 10
8 9
9 8
10 7

8 10
9 9
10 8

9 10
10 9

10 10

3ans :- 303
*/

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0, ans1 = 0;

    for (ll i = 1; i <= n; i++)
    {
        ll temp = ans1;
        ll mx = 0;

        ll x = 0;

        for (ll j = i; j <= n; j++)
        {
            mx = max(mx, j * (n - x));
            cout << j << " " << n - x << endl;
            temp += j * (n - x);
            x++;
        }
        cout << "\n";
        ans = max(ans, temp - mx);

        ans1 += (i * i);
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}