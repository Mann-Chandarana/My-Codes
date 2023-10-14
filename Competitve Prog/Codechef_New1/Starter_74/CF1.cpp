/* Chef and Babla */

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

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int pos_mini = INT_MAX, negi_maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (vec[i] < 0)
                negi_maxi = max(negi_maxi, vec[i]);
            else
                pos_mini = min(pos_mini, vec[i]);
        }

        if (pos_mini == 0 || negi_maxi == 0)
        {
            cout << -1 << endl;
        }
        else if (negi_maxi == INT_MIN)
        {
            cout << pos_mini - 1 << endl;
        }
        else if (pos_mini == INT_MAX)
        {
            cout << abs(negi_maxi) - 1 << endl;
        }
        else
        {
            cout << min(abs(negi_maxi), pos_mini)-1 << endl;
        }
    }

    return 0;
}