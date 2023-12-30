/*** A. 2023 ***/

// https://codeforces.com/contest/1916/problem/A

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

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vi b(n);
        ll product = 1;

        for (auto &i : b)
            cin >> i, (product = product * 1ll * i);

        if (2023 % product != 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << (2023 / product) << " ";
            k--;
            while (k--)
                cout << 1 << " ";

            cout << endl;
        }
    }

    return 0;
}