/******************* Plus 2 or Minus 1 *******************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int y;
        cin >> y;

        if (y == 0)
            cout << 1 << endl;
        else
            cout << 2 * y + y << endl;
    }

    return 0;
}