/* Count total set bits :- https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1 */

#include <bits/stdc++.h>
using namespace std;

/* O(N^2) It will give time limit exceed */

int TotalSetBits(int n)
{
    int bits = 0;
    while (n > 0)
    {
        if ((n & -n) > 0)
        {
            bits++;
            n = (n & n - 1);
        }
    }
    return bits;
}

int countSetBits(int n)
{
    int Total = 0;

    for (int i = 1; i <= n; i++)
    {
        Total += TotalSetBits(i);
    }
    return Total;
}

/* Optimised solution -- O(LogN) */

int power2_closeTo_n(int n)
{
    int i = 0;
    while ((1 << i) <= n)
        i++;

    return i - 1;
}

int countSetBits(int n)
{
    if (n == 0)
        return 0;

    int x = power2_closeTo_n(n);

    int value1 = ((1 << (x - 1)) * x); /* Formula :- (2^(x-1) *x) */
    int value2 = n - (1 << x) + 1;     // For finding total number of outer ones

    int value = n - (1 << x);

    int answer = value1 + value2 + countSetBits(value);

    return answer;
}

/* More Optimised Solution -- O(1) */

int countSetBits(int n)
{
    n++;
    int answer = 0, cnt;
    for (int i = 0; i < 32; i++)
    {
        int curr2 = 1 << i;
        int last2 = (1 << (i - 1));

        if (n % curr2 > last2)
            answer += (last2 * (n / curr2)) + (n % last2);
        else if (n % curr2 <= last2)
            answer += (last2 * (n / curr2));

        cnt = 1 << i;
        if (cnt > n)
            break;
    }
    return answer;
}

int main()
{
    cout << countSetBits(4) << endl;
    return 0;
}