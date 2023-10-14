/* LCM hates GCD */

#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    int r = 0, a, b;
    a = (x > y) ? x : y; // a is greater number
    b = (x < y) ? x : y; // b is smaller number

    r = b;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

int lcm(int x, int y)
{
    int a;
    a = (x > y) ? x : y; // a is greater number
    while (true)
    {
        if (a % x == 0 && a % y == 0)
            return a;
        ++a;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int x = gcd(a, b);

        cout << lcm(a, x) - __gcd(b, x) << endl;
    }

    return 0;
}