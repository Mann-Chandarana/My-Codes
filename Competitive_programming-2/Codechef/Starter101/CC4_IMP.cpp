/* https://www.codechef.com/problems/XORDIF */

#include <bits/stdc++.h>
using namespace std;

/* Approach -1)  */

void solve()
{
    int a, b;
    cin >> a >> b;
    int x = 0;
    int d = abs((a ^ x) - (b ^ x));
    for (int i = 0; i < 30; i++)
    {
        int m = (1 << i);
        x = (x | m);
        int nd = abs((a ^ x) - (b ^ x));
        if (nd < d)
            d = nd;

        else
            x = (x ^ m);
    }
    cout << x << endl;
}

/* Approach -2) */

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a < b)
        swap(a, b);

    int bit = -1;

    for (int i = 29; i >= 0; i--)
    {
        int x = (1 << i);
        if ((a & x) != (b & x))
        {
            bit = i;
            break;
        }
    }
    int ans = 0;

    for (int i = bit - 1; i >= 0; i--)
    {
        int x = (1 << i);
        if ((a & x) > 0 and (b & x) == 0)
            ans += x;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}