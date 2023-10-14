/* Donation Rewards */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n >= 0 and n <= 3)
            cout << "BRONZE" << endl;

        else if (n <= 6)
            cout << "SILVER" << endl;

        else if(n>6)
            cout << "GOLD" << endl;
    }

    return 0;
}