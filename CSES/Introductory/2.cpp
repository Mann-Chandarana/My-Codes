/* Missing Number */

#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vll;

#define ll long long
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    ll n, sum = 0;
    cin >> n;

    vll vec(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    cout << (((n * 1LL * (n + 1)) / 2) - sum) << endl;

    return 0;
}