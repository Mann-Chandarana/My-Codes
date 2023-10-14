#include <iostream>
using namespace std;

// int main()
// {
//     int pocketmoney = 3000;
//     for (int dates = 0; dates <= 30; dates++)
//     {
//         if (dates % 2 == 0)
//         {
//             continue;
//         }
//         if (pocketmoney == 0)
//         {
//             break;
//         }

//         cout << "Go out for today!" << endl;
//         pocketmoney = pocketmoney - 500;
//     }

//     return 0;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int i;
//     for (i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << "Non prime" << endl;
//             break;
//         }
//     }
//     if (i == n)
//     {
//         cout << "Prime" << endl;
//     }

//     return 0;
// }

int main()
{
    int a, b, i;
    cin >> a >> b;
    for (int num = a; num <= b; num++)
    {
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                break;
            }
        }
        if (i == num)
        {
            cout << "Prime" << endl;
        }
    }

    return 0;
}
