///////// Prime factorization using sieve of erathonesis

#include <bits/stdc++.h>
using namespace std;

void primefactor(int n)
{
    int spf[100] = {0};

    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < n; j++)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    while (n != 1)
    {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
}

int main()
{

    return 0;
}