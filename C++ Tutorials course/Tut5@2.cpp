#include <iostream>
#include <math.h>
using namespace std;

///// Palidrome
int main()
{
    int n;
    cin >> n;
    int reverse = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n = n / 10;
    }
    cout << reverse<<endl;

    return 0;
}

////// Armstrong Number
// int main()
// {
//     int n;
//     cin >> n;

//     int sum = 0;
//     int originaln = n;
//     while (n > 0)
//     {
//         int lastdigit = n % 10;
//         sum += pow(lastdigit, 3);
//             n = n / 10;
//     }
//     if (sum == originaln)
//     {
//         cout << "Armstrong number" << endl;
//     }
//     else
//     {
//         cout << "not Armstrong number" << endl;
//     }

//     return 0;
// }
