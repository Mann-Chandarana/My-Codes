/* 
   Rectangular Tiling
   https://www.codechef.com/START92D/problems/RCT
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int W, L;
        cin >> W >> L;

        if (W & 1 and L & 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}