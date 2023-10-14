/* Geeks for Geeks :- calculate-square-of-a-number-without-using-and-pow */

#include <bits/stdc++.h>
using namespace std;

/*
Approach -1) :-

11^2 = (11*11)
     = (11*(2^3+2^1+2^0))
     = (11*(2^3)+11*(2^1)+11(2^0))
     = (11<<3 + 11<<1 + 11<<0)

so this way we can calculate sqaure of the number
*/

int solve()
{
    int n;
    cin >> n;

    int x = n;
    int i = 0, answer = 0;

    while (x)
    {
        if (x & 1)
            answer += (n << i);

        i++;
        x = x >> 1;
    }
    return answer;
}

/* Approach -2)

Solution :-
1) x = 2*n + 1   --- for odd number
2) x = 2*n       --- for even number

taking square x^2 = 4*(x^2) + 4^x + 1   -- for odd number
taking square x^2 = 4*(x^2)   --- for even number
*/

int square(int n)
{
    if (n == 0)
        return 0;

    if (n < 0)
        n = -n;

    int x = n >> 1;

    if (n & 1)
        return (square(x) << 2) + (x << 2) + 1;
    else
        return (square(x) << 2);
}

/* Approach -3) */

int solve()
{
    int n;
    cin >> n;

    if (n < 0)
        n = -n;

    int answer = 0;
    for (int i = 1; i <= n; i++)
        answer += n;
    
    return answer;
}

/* Approach -4) 
If we want to find the sqaure of the number n
then add first n odd number
*/

int main()
{
    cout << square(4) << endl;
    return 0;
}