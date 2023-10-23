/* https://codeforces.com/contest/1888/problem/A */

/* A. Chemistry */

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
    int n, k;
    cin >> n >> k;

    vector<int> freq(26, 0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'a']++;

    int odd = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == 0)
            continue;

        else if (freq[i] & 1)
            odd++;
    }

    if (odd > k + 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}