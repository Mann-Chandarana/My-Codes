/* Weird Algorithm */

#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    ll n;
    cin >> n;

    while (n > 1)
    {
        cout << n << " ";
        if (n & 1)
            n = ((3 * (1LL) * n) + 1);
        else
            n /= 2;
    }
    if (n == 1)
        cout << n << endl;

    return 0;
}