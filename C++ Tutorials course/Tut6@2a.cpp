#include <iostream>
#include <math.h>
using namespace std;

// int fact(int n)
// {
//     int factorial = 1;
//     for (int i = 2; i <= n; i++)
//     {
//         factorial *= i;
//     }
//     return factorial;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int ans = fact(n);
//     cout << ans;
//     return 0;
// }

int fact(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}
int main()
{
    int n, r;
    cin >> n >> r;
    int ans = fact(n) / (fact(r) * fact(n - r));
    cout << ans;
}