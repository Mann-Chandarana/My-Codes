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

    int mini = INT_MAX, maxi = INT_MIN;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        mini = min(mini, b);
        maxi = max(maxi, a);
    }
    cout << maxi - mini << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}