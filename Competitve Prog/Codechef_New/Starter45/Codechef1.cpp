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
        vector<int> vec(n);
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            sum = sum ^ vec[i];
        }
        if (sum == 0)
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