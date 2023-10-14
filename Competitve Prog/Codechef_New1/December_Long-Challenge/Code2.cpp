/* Divisible by k */

/*https://www.codechef.com/DEC221C/problems-old/DIVBYK */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long N, K;
        cin >> N >> K;
        vector<long long> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        long long val = 1;

        for (int i = 0; i < N; i++)
        {
            val = (val * arr[i]) % K;
        }
        if (val == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}