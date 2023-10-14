/* Gcd of Subarrays */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        
        long long sum = (n * (n + 1)) / 2;

        if (k < sum)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (long long i = 0; i < n - 1; i++)
            {
                cout << "1"
                     << " ";
            }
            cout << (k - sum+1) << endl;
        }
    }

    return 0;
}