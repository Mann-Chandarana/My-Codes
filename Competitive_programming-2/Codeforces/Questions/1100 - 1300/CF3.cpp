// https://codeforces.com/problemset/problem/1873/E

/* E. Building an Aquarium :- 1100 */

/*
We need to find the maximum height with a certain upper bound — this is a tell-tale sign of binary search. If you don't know what that is, you should read this Codeforces EDU article.

For a given value of h, in the ith column we will need h−ai units of water if h≥ai, or 0 units otherwise. (This is equal to max(h−ai,0), why?) So we can compute the amount of water for all n columns by simply iterating through and summing the total amount of water needed for each column, and see if it's not larger than x.

Then you can binary search on the optimal value of h. The model solution uses the starting bounds l=0 r=2ai+ε because the optimal height could be ai+x .So the complexity is O(nlogai) per testcase.

*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

bool isPossible(ll h, ll x, vector<ll> &arr)
{
    ll n = arr.size();

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < h)
            ans += (h - arr[i]);
    }
    return ans <= x;
}

void solve()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> arr(n);

    for (auto &i : arr)
        cin >> i;

    ll low = 0, high = 2e9+7;   // For high value see the above solution
    ll ans = 0;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (isPossible(mid, x, arr))
            ans = mid, low = mid + 1;
        else
            high = mid - 1;
    }

    cout << ans << endl;
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