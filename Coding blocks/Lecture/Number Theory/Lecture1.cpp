/////////// Prime number in a given range

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int p[100000] = {0};
    Prime_sieve(p);

    int cSum[100000] = {0};

    for (int i = 1; i < 100000; i++)
    {
        cSum[i] = cSum[i - 1] + p[i];
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << cSum[b] - cSum[a - 1] << endl;
    }

    return 0;
}