#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    ll n;
    cin >> n;

    vi vec(n);

    for (auto &i : vec)
        cin >> i;

    ll moves = 0;

    for (ll i = 1; i < n; i++)
    {
        if (vec[i] < vec[i - 1])
        {
            moves += (vec[i - 1] - vec[i]);
            vec[i] = vec[i - 1];
        }
    }
    cout << moves << endl;

    return 0;
}