////////// No of divisors

#include <bits/stdc++.h>
using namespace std;

int no_of_divisors(int m, vector<int> &prime)
{

    int i = 0;
    int p = prime[i];
    int ans = 1;

    while (p * p <= m)
    {
        if (m % p == 0)
        {
            int cnt = 0;
            while (m % p == 0)
            {
                cnt++;
                m = m / p;
            }
            ans = (cnt + 1) * ans;
        }
        // Go to next position
        i++;
        p = prime[i];
    }

    if (m != 1)
    {
        ans = ans * 2;
    }

    return ans;
}

int main()
{

    return 0;
}