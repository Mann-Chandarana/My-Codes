/* https://codeforces.com/problemset/problem/1/A */

/* 100:- A. Theatre Square */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();
    ll n, m, a;
    cin >> n >> m >> a;

    ll answer = ceil((double)n / a) * ceil((double)m / a);
    cout << answer << endl;

    return 0;
}