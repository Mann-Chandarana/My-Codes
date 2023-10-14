// Find a value whose XOR with a given value is maximum :- Easy marked

#include <bits/stdc++.h>
using namespace std;

long long findValueWhoseXORWithGivenNumberIsMaximum(long long X)
{
    int m = 61;
    long long l = (1ll << m) - 1;
    return l ^ X;
}

int main()
{
    return 0;
}