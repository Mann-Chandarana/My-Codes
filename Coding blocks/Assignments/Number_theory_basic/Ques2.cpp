/////////////////  Deepak and primes

#include <iostream>
typedef long long ll;
using namespace std;

/////////////////// Sieve of Eratosthenes

// void prime_sieve(ll *p, ll n)
// {
//     for (ll i = 2; i < 100000; i++)
//     {
//         p[i] = 1;
//     }

//     for (ll i = 2; i < 100000; i++)
//     {
//         if (p[i] == 1)
//         {
//             for (ll j = i * i; j < 100000; j += i)
//             {
//                 p[j] = 0;
//             }
//         }
//     }

//     ll i = 0, j = 1;
//     while (true)
//     {
//         if (p[i] == 1)
//         {
//             if (j == n)
//             {
//                 cout << i << endl;
//                 break;
//             }
//             j++;
//         }
//         i++;
//     }
// }

//////////////////////// Using Optimised approach

void prime_sieve(ll *p,int n)
{
    for (ll i = 3; i <= 100000; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i <= 100000; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= 100000; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;

    ll i = 0, j = 1;
    while (true)
    {
        if (p[i] == 1)
        {
            if (j == n)
            {
                cout << i << endl;
                break;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll p[100000] = {0};
        ll n;
        cin >> n;
        prime_sieve(p, n);
    }

    return 0;
}