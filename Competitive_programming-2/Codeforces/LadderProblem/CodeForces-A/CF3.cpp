/* Twins :- 900 */

/* https://codeforces.com/problemset/problem/160/A */

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

    vi vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    ll sum = accumulate(all(vec), 0);

    sort(all(vec), greater<int>());

    ll sum1 = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum1 += vec[i];
        ans++;

        if (sum1 > sum - sum1)
            break;
    }
    cout << ans << endl;
}

int main()
{
    fastread();

    solve();

    return 0;
}