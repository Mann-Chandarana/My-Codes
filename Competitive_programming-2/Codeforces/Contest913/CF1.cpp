#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

/* A. Rook */

/* https://codeforces.com/contest/1907/problem/A */

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    string s;
    cin >> s;

    for (char i = '1'; i <= '8'; i++)
    {
        if (s[1] != i)
            cout << s[0] << i << endl;
    }

    for (char i = 'a'; i <= 'h'; i++)
    {
        if (s[0] != i)
            cout << i << s[1] << endl;
    }
}

int main()
{
    fastread();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}