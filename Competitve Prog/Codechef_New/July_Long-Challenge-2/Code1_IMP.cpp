//////////// Hungry chef

/*
a+b = n
ax+by = n

by replacing value of a by n-b
(n-b)*x+by = n

b= (r-nx)/y-x
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mn = n * x;
        int mx = n * y;

        if (mn > r)
        {
            cout << "-1\n";
        }
        else if (r >= mx)
        {
            cout << 0 << " " << n << "\n";
        }
        else
        {
            int b = (r - mn) / (y - x);
            cout << n - b << " " << b << endl;
        }
    }

    return 0;
}