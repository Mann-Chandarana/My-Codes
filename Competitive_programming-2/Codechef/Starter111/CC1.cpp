#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;

    string str;
    cin >> str;

    vll freq(26, 0);

    for (ll i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    ll answer = 1;

    for (ll i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            answer = (answer * (freq[i] + 1)) % mod;
    }
    cout << (answer - 1 + mod) % mod << endl;
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