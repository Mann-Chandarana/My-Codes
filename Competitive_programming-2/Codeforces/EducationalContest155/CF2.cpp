/* https://codeforces.com/contest/1879/problem/B */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;

    vector<ll> vec1(n), vec2(n);

    ll mini_1 = LONG_MAX;
    ll mini_2 = LONG_MAX;

    ll sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i];
        sum1 += vec1[i];
        mini_1 = min(mini_1, vec1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> vec2[i];
        sum2 += vec2[i];
        mini_2 = min(mini_2, vec2[i]);
    }

    cout << min((sum1 + (n * 1LL * mini_2)), (sum2 + (n * 1LL * mini_1)))<<endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}