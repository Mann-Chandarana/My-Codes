/* Set K Bits :- Easy marked */

#include <bits/stdc++.h>
using namespace std;

int setKBits(int n, int k)
{
    int mask = (1 << k) - 1;

    return (n | mask);
}

int main()
{
    return 0;
}