#include <iostream>
using namespace std;

////////// Star pattern
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = 1; j <= (2 * i - 1); j++)
//         {
//             cout << "*"
//                  << " ";
//         }
//         cout << endl;
//     }
//     for (int i = n; i >= 1; i--)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = 1; j <= (2 * i - 1); j++)
//         {
//             cout << "*"
//                  << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

////////// Zig Zag pattern
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
            {
                cout << "*";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
