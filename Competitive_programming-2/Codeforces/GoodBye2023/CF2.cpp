/*** B. Two Divisors ***/

/* https://codeforces.com/contest/1916/problem/B */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int lcm(ll a, ll b)
{
    return (a * 1ll * b) / __gcd(a, b);
}

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (a == 1)
        cout << b * 1LL * b << endl;
    else if (lcm(a, b) == b)
        cout << lcm(a, b) * (b / a) << endl;

    else
        cout << lcm(a, b) << endl;
}

int main()
{
    fastread();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}