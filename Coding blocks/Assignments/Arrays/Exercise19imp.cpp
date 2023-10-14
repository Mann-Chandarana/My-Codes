// Pythagorian triplet

#include <iostream>
#include <math.h>
typedef long long int ll;
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 2)
    {
        cout << "-1";
    }

    else if (n % 2 == 0)
    {
        long long var = 1 * n * n / 4;
        cout << var - 1 << " ";
        cout << var + 1;
    }

    else if (n % 2 != 0)
    {
        long long var = 1 * n * n + 1;
        cout << var / 2 - 1 << " ";
        cout << var / 2;
    }
    return 0;
}