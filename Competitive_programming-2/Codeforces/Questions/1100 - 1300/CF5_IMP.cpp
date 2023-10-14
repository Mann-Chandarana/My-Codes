/* NDONE */

/* https://codeforces.com/contest/1850/problem/F */

/* F. We Were Both Children :- 1300 */

/*
Here we have to mark all the multiple of the array that are <=n
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    ll n;
    cin >> n;

    vi mx(n + 1, 0), count(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x <= n)
            count[x]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            mx[j] += count[i];
    }

    cout << *max_element(all(mx)) << endl;
}

int main()
{
    fastread();

    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}