/* https://www.codechef.com/START101C/problems/SMARTER */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        float l, v1, v2;
        cin >> l >> v1 >> v2;

        int t_speed = ceil(l / v1);
        int h_speed = ceil(l / v2);

        if (t_speed == h_speed)
            cout << -1 << endl;
        else if (t_speed - h_speed > 1)
            cout << (t_speed - h_speed - 1) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}