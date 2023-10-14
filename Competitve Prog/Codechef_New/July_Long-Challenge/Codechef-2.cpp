//// The journey of knight

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x1, y1, x2, y2;
    cin >> t;

    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        if ((abs(x1 - x2) % 2 == 0 && abs(y1 - y2) % 2 == 0) || (abs(x1 - x2) % 2 != 0 && abs(y1 - y2)%2 != 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}