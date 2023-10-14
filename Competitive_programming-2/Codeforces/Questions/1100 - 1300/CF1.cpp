/* https://codeforces.com/problemset/problem/1870/B */

/* B. Friendly Arrays - 1200 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    int B = 0;

    for (auto &i : a)
        cin >> i;

    for (auto &j : b)
        cin >> j, B |= j;

    int A = 0, A1 = 0;

    for (auto i : a)
        A ^= i, A1 ^= (B|i);

    if (n & 1)
        cout << A << " " << A1 << endl;
    else
        cout << A1 << " " << A << endl;
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