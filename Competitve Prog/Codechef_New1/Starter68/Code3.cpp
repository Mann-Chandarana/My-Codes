/* Xor product */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> vec(n);

        int count_1 = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            if (vec[i] == 1)
            {
                count_1++;
            }
        }

        if (count_1 != 0)
        {
            vector<int> even, odd;

            for (int i = 0; i < n; i++)
            {
                if (vec[i] == 1)
                {
                    continue;
                }
                if (vec[i] % 2 == 0)
                {
                    even.push_back(vec[i]);
                }
                else
                {
                    odd.push_back(vec[i]);
                }
            }
            sort(even.begin(), even.end());
            long long int multi = 1;
            for (int i = 0; i < even.size(); i++)
            {
                if (count_1 == 0)
                {
                    while (i < even.size())
                    {
                        multi *= even[i] % 998244353;
                        i++;
                    }
                    break;
                }
                multi *= (even[i] ^ 1)%998244353;
                count_1--;
            }

            for (auto element : odd)
            {
                multi *= element % 998244353;
            }
            cout << (multi) << endl;
        }

        else
        {
            int multi = 1;
            for (int i = 0; i < n; i++)
            {
                multi *= (vec[i])%998244353;
            }
            cout << multi << endl;
        }
    }
    return 0;
}