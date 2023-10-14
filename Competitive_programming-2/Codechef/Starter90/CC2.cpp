/* Favourite Number */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, A;

    while (t--)
    {
        cin >> A;
        if (A % 2 == 0 and A % 7 == 0)
            cout << "Alice" << endl;

        else if (A % 2 != 0 and A % 9 == 0)
            cout << "Bob" << endl;

        else
            cout << "Charlie" << endl;
    }

    return 0;
}