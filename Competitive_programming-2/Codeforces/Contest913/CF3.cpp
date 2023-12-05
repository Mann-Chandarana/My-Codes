/* C. Removal of Unattractive Pairs */

/* https://codeforces.com/contest/1907/problem/C */

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
    int n;
    cin >> n;

    string str;
    cin >> str;

    vi freq(26, 0);

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    int value = 0;

    for (auto element : freq)
    {
        if (element > (n / 2))
            value = element;
    }

    if (value != 0)
        cout << (n - (2 * (n - value))) << endl;
    else
    {
        if (n & 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
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