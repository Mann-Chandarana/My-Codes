/* Copy set Bits in a range :- https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1 */

#include <bits/stdc++.h>
using namespace std;

/* O(N) Solution */

int copySetBits(int x, int y, int l, int r)
{
    if (l < 1 and r > 32)
        return -1;

    for (int i = l; i <= r; i++)
    {
        int mask = 1 << (i - 1);

        if (y & mask)
            x = x | mask;
    }

    return x;
}

/* O(1) Solution */

int copySetBits(int x, int y, int l, int r)
{
    int mask1 = (1 << (r - l + 1)) - 1;
    mask1 = mask1 << (l - 1);

    int mask2 = y & mask1;

    int final_answer = x | mask2;

    return final_answer;
}

int main()
{
    cout<<copySetBits(10,13,2,3)<<endl;
    return 0;
}