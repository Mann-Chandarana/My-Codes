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
    ll n;
    cin >> n;

    vector<ll> vec(n);

    for (auto &i : vec)
        cin >> i;

    ll maxi = *max_element(all(vec));

    ll element = maxi + 1;

    ll answer = 0;

    for (auto i : vec)
        answer += abs(i - element);

    cout << answer << endl;
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