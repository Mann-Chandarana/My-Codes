/* Problem  */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll Alice, Bob;
        cin >> Alice >> Bob;

        if (!((Alice - Bob) & 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}