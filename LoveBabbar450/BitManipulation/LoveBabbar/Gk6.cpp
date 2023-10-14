// Find position of set bit :-  https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

#include <bits/stdc++.h>
using namespace std;

/* O(1) :- Solution */

int findPosition(int N)
{
    if ((N & N - 1) || N == 0)
        return -1;

    int t = log(N) / log(2);
    return (t + 1);
}

/* O(N) Solution */

int findPosition(int N)
{
    if ((!N) || (N & N - 1))
        return -1;

    int i = 1, pos = 1;

    while (!(i & N))
    {
        i = i << 1;
        ++pos;
    }

    return pos;
}

int main()
{
    cout << findPosition(6) << endl;
    return 0;
}