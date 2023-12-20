/* C. Game with Reversing */

/* https://codeforces.com/problemset/problem/1834/C */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

ll check(int n, string &s, string &t)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            cnt++;
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;

    string S, T;
    cin >> S >> T;

    ll ans1 = check(n, S, T);
    reverse(all(T));
    ll ans2 = check(n, S, T);

    if (ans2 == 0)
    {
        string str = T;
        reverse(all(T));

        if (str != T)
            cout << 2 << endl;
        else
            cout << ans2 << endl;
    }
    else
    {
        ans1 = 2 * ans1 - (ans1 % 2);
        ans2 = 2 * ans2 - (1 - ans2 % 2);
        cout << min(ans1, ans2) << endl;
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