//////// Finding prime factors

#include <bits/stdc++.h>
using namespace std;

vector<int> factorize(int m, vector<int> &prime)
{
    vector<int> factors;
    factors.clear(); // Create am empty vector

    int i = 0;
    int p = prime[i];

    while (p * p <= m)               // It means if a number has factor in range between 0 to root(m)
    {                                //  then it is not a prime number other wise it is a prime number
        if (m % p == 0)
        {
            factors.push_back(p);
            while (m % p == 0)
            {
                m = m / p;
            }
        }
        // Go to next position
        i++;
        p = prime[i];
    }

    if (m != 1)
    {
        factors.push_back(m);
    }

    return factors;
}

int main()
{

    return 0;
}