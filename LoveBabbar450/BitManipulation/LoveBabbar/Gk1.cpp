/* https://practice.geeksforgeeks.org/problems/set-bits0143/1 */

#include <bits/stdc++.h>
using namespace std;

/* Important approach */

int setBits(int N)
{
    int count = 0;
    while (N > 0)
    {
        int last_set_bit = N & -N; // Will help to find the last set bit
        count++;
        N -= last_set_bit;
    }
    return count;
}

/* Brute force approach */

int setBits(int N)
{
    int count = 0;

    for (int i = 0; i <= 31; i++)
    {
        int mask = 1 << i;
        if (N & mask)
            count++;
    }

    return count;
}

int main()
{
    return 0;
}