/* Trailing Zeros */

/* https://cses.fi/problemset/result/7856993/ */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    ll n;
    cin >> n;

    ll answer = 0, current = 5;

    while (current <= n)
    {
        answer += (n / current);
        current *= 5;
    }
    cout << answer << endl;

    return 0;
}