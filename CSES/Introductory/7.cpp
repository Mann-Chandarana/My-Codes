#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;
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
    fastread();
    ll n;
    cin >> n;

    ll sum = (n *(1LL)* (n + 1)) / 2;

    if (sum & 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        vector<long long> check(n + 1, false);

        vll first, second;
        ll half = sum / 2;

        for (ll i = n; i >= 0; i--)
        {
            if (half >= i)
            {
                half -= i;
                check[i] = true;
            }
            else
            {
                if (half > 0)
                    check[half] = true;
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            if (check[i] == 1)
                first.pb(i);
            else
                second.pb(i);
        }

        cout << first.size() << endl;

        for (auto element : first)
            cout << element << " ";

        cout << endl;

        cout << second.size() << endl;

        for (auto element : second)
            cout << element << " ";
    }

    return 0;
}