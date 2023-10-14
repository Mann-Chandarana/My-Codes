///// The subarray xor

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t, n, k;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vector<int> vec(n);
        ll sum = 0, i = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        ll mini = INT_MAX;

        while (j < n)
        {
            if (j != -1 && vec[j] > k)
            {
                mini = 1;
                sum = 0;
                j++;
                i = j;
                break;
            }

            sum = sum ^ vec[j];
            // cout << sum << endl;

            if (sum >= k)
            {
                // cout << "Answer of Xor " << i << " " << j << endl;
                mini = min(mini, j - i + 1);
                sum ^= vec[i];
                i++;
            }
            j++;
        }
        if (mini != INT_MAX)
        {
            cout << mini << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}