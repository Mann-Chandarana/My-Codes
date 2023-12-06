/* Number Spiral */

/* https://cses.fi/problemset/task/1071/ */

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
    ll y, x;
    cin >> y >> x;

    if (x >= y)
    {
        if (x & 1)
            cout << (x * (1LL) * x) - (y - 1) << endl;
        else
            cout << ((x - 1) * (1LL) * (x - 1)) + 1 + (y - 1) << endl;
    }
    else
    {
        if (y & 1)
            cout << ((y - 1) * (1LL) * (y - 1)) + 1 + (x - 1) << endl;
        else
            cout << (y * (1LL) * y) - (x - 1) << endl;
    }
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