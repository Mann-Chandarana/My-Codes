#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        ll steps = 0,size = 2*n;
        vector<ll> ans(size);

        for (int i = 0; i < 2 * n; i++)
        {
            cin >> ans[i];
        }

        vector<ll> half1, half2;

        for (int i = 0; i < 2 * n; i++)
        {
            if (ans[i] > size / 2 and i < size / 2)
                half1.push_back(i + 1);

            if (ans[i] <= size / 2 and i >= size / 2)
            {
                half2.push_back(i + 1);
            }
        }

        for (int i = 0; i < half1.size(); i++)
        {
            steps += abs(half1[i] - half2[i]);
        }

        cout << steps << endl;
    }

    return 0;
}