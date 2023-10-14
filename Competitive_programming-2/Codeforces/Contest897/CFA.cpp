/* https://codeforces.com/contest/1867/problem/A */

/*
Solution :-
1) assign the index to the number so we can remember the indexes and then sort the number
2) Then start assigning the number in decreasing order

because a:- 101 102 103
        b:-  3   2   1
        c:-  99  100 102

will give the maximum number of the distinct elements
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define pll pair<ll, ll>

void solve()
{
    ll n;
    cin >> n;

    vector<pll> vec;

    for (ll i = 0; i < n; i++)
    {
        ll no;
        cin >> no;

        vec.push_back({no, i});
    }

    sort(all(vec));

    vector<ll> ans(n);

    ll number = n;

    for (ll i = 0; i < n; i++)
        ans[vec[i].second] = number--;

    for (auto &element : ans)
        cout << element << " ";

    cout << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}