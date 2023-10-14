/* DONE */

/* https://codeforces.com/problemset/problem/1873/B */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;

    vi vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(all(vec));

    vec[0]++;

    ll product = 1;

    for (int i = 0; i < n; i++)
        product *= vec[i];

    cout << product << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}