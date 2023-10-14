/// Nearest count

#include <bits/stdc++.h>
using namespace std;


////// Easy soluton of this problem
// int main()
// {
//     int t, x, y;
//     cin >> t;

//     while (t--)
//     {
//         cin >> x >> y;
//         int x = (x + y) / 2;
//         int z = max(abs(x - z), abs(y - z));
//         cout << z << endl;
//     }

//     return 0;
// }

int main()
{
    int t, x, y;
    cin >> t;

    while (t--)
    {
        cin >> x >> y;
        if (abs(x - y) == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            int diff = abs(x - y);
            int answer = diff / 2 + diff % 2;
            cout << answer << endl;
        }
    }

    return 0;
}
