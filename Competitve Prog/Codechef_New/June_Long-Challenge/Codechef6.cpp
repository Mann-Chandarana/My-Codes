///////////// Strong element very important

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> vec(n);
        vector<int> suffix(n);
        vector<int> prefix(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        prefix[0] = vec[0];

        for (int i = 0; i < n; i++)
        {
            prefix[i] = __gcd(prefix[i - 1], vec[i]);
        }

        suffix[n - 1] = vec[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = __gcd(suffix[i + 1], vec[i]);
        }

        int strong = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 && suffix[i+1] > 1)
            {
                strong++;
            }
            else if (i == n - 1 && prefix[n - 2] > 1)
            {
                strong++;
            }
            else if (__gcd(prefix[i - 1], suffix[i + 1]) > 1)
            {
                strong++;
            }
        }
        cout << strong << endl;
    }

    return 0;
}