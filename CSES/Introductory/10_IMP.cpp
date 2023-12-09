/* Coin Piles */

/* https://cses.fi/problemset/result/7857096/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    ll a, b;
    cin >> a >> b;

    if ((a + b) % 3 == 0 and min(a, b) * 2 >= max(a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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