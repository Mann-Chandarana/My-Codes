#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))


/******* Using O(N) ********/

void solve()
{
    ll n, k;
    cin >> n >> k;

    vi a(n), h(n);

    for (auto &i : a)
        cin >> i;

    for (auto &i : h)
        cin >> i;

    ll left = 0, right = 0, ans = 0, prev = 0, sum = 0;

    while (right < n)
    {
        if (a[right] > k)
        {
            right++;
            left = right;
            prev = 0;
            sum = 0;
            continue;
        }
        if ((prev % h[right] == 0) and sum + a[right] <= k)
        {
            sum += a[right];
            prev = h[right];
            ans = max(ans, right - left + 1);
            right++;
        }
        else if (prev % h[right] != 0)
            sum = 0, prev = 0, left = right;

        else if (sum + a[right] > k)
        {
            sum -= a[left];
            left++;
            if (left == right)
                prev = 0;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}