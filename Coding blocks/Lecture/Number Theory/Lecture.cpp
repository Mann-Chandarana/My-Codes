/////////// Prime Sieve

#include <bits/stdc++.h>
using namespace std;

//////////// Complexity is O(loglogn)

/// Optimised approach
void Prime_sieve(int *p)
{
    ///////// Mark all odd number as prime
    for (int i = 3; i < 100000; i += 2)
    {
        p[i] = 1;
    }

    // Sieve

    for (int i = 3; i < 100000; i++)
    {
        if (p[i] == 1)
        {
            ////// Mark all mutiple of i as not prime
            for (int j = i * i; j < 100000; j += i)
            {
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;
}

// void prime_sieve(int n)
// {
//     int prime[100] = {0};

//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             for (int j = i * i; j < n; j += i)
//             {
//                 prime[j] = 1;
//             }
//         }
//     }

//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i] == 0)
//         {
//             cout << i << " ";
//         }
//     }
// }

int main()
{

    return 0;
}