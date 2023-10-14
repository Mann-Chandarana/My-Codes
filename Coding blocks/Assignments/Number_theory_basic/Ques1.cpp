/////////////// Modular exponentiation

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ll a, b, c, temp = 1;
    cin >> a >> b >> c;

    for (int i = 0; i < b; i++)
    {
        temp = (temp % c) * (a % c);
    }
    cout << temp%c << endl;

    return 0;
}