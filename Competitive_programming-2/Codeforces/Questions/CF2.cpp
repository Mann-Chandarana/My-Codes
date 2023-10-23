/* B. Raspberries */

/* https://codeforces.com/contest/1888/problem/B */

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
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n, k, mini = INT_MAX;
        cin >> n >> k;
        int even = 0;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            if (!(a & 1))
                even++;

            a %= k;

            if (a == 0)
                mini = 0;
            else
                mini = min(mini, k - a);
        }
        if (k == 4)
            mini = min(mini, max(0, 2 - even));

        cout << mini << endl;
    }

    return 0;
}