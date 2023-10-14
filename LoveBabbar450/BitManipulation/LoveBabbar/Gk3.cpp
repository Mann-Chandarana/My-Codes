#include <bits/stdc++.h>
using namespace std;

/* Brute force solution */

int countBitsFlip(int a, int b)
{
    int count = 0;
    for (int i = 0; i <= 31; i++)
    {
        if (((a >> i) & 1)^((b >> i) & 1))
            count++;
    }
    return count;
}

/* Better appraoch */

int countBitsFlip(int a, int b)
{
    int x = a ^ b;
    int count = 0;
    while (x)
    {
        if (x & 1)
            count++;
        x >>= 1;
    }
    return count;
}

int main()
{
    cout << countBitsFlip(10, 20) << endl;
    return 0;
}