#include <iostream>
#include <math.h>
using namespace std;

/////////// Sum of n number
// int sum(int n)
// {
//     int ans = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         ans += i;
//     }
//     return ans;
// }
// int32_t main()
// {
//     int n;
//     cin >> n;
//     cout << sum(n) << endl;
// }



/////////// Pythagorian triplet

bool check(int x, int y, int z)
{
    int a = max(x, max(y, z));
    int b, c;
    if (a == x)
    {
        b = y;
        x = z;
    }
    else if (a == y)
    {
        b = z;
        c = x;
    }
    else
    {
        b = x;
        c = y;
    }
    if (a*a == b*b + c*c)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    if (check(x, y, z))
    {
        cout << "Pythagorian triplet";
    }
    else
    {
        cout << "Not a pythagorian triplet";
    }

    return 0;
}
