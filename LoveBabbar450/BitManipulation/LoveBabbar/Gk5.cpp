/* Power of 2 :- https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1 */

#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
    if (n <= 0)
        return 0;

    return (n & (n - 1)) == 0;
}

int main()
{
    cout << isPowerofTwo(8) << endl;
    return 0;
}