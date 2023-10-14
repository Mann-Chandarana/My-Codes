////////// Euclid's algorithm

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int main()
{

    return 0;
}