/* https://codeforces.com/contest/1869/problem/A */

/*
Solution :-

1) for even numbers 
    x^x = 0

2) for odd numbers
    x^x^x = x

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);

    for (auto &i : arr)
        cin >> i;

    if (!(n & 1)) // If n is even
    {
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
    else // If n is odd
    {
        cout << 4 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << n - 1 << " " << n << endl;
        cout << n - 1 << " " << n << endl;
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