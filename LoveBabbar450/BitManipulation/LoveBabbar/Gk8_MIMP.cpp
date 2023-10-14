/* Divide two integers without using multiplication , division and mod operator */

#include <bits/stdc++.h>
using namespace std;

/* Using Maths :- Will give time limit exceded*/

long long divide(long long dividend, long long divisor)
{
    int sign = (dividend < 0) ^ (divisor < 0);

    long long quotient = 0;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor)
    {
        dividend -= divisor;
        quotient++;
    }

    return sign == 1 ? -quotient : quotient;
}

/* Using Maths + Bitmanipulation */

/*  
y = (x * d) + r

d= 2^0 + 2^1 + 2^2 + 2^3

*/

long long divide(long long dividend, long long divisor)
{
    int sign = (dividend < 0) ^ (divisor < 0);

    int quotient = 0;

    dividend = abs(dividend);
    divisor = abs(divisor);

    for (int i = 31; i >= 0; i--)
    {
        if ((divisor << i) <= dividend)
        {
            dividend -= (divisor << i);
            quotient += (1ll << i);
        }
    }

    return sign == 1 ? -quotient : quotient;
}

int main()
{
    return 0;
}