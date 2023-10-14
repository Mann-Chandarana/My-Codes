/******************* Monopoly *******************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int P, Q, R, S, sum = 0;
        cin >> P >> Q >> R >> S;

        sum = P + Q + R + S;

        if (P > sum - P || Q > sum - Q || R > sum - R || S > sum - S)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }

    return 0;
}