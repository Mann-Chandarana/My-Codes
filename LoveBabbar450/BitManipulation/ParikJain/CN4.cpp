/* Flip given bits :- Easy */

#include <bits/stdc++.h>
using namespace std;

int flipSomeBits(int num, vector<int> &arr, int n)
{
    int answer = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int mask = (1 << (arr[i] - 1));
        if ((1 << (arr[i] - 1)) & num)
            num = (num & ~mask);
        else
            num = num | mask;
    }
    return num;
}

int main()
{

    return 0;
}