#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int n, vector<ll> vec, ll mid)
{
    vector<ll> newArray = vec;

    if (newArray[0] > mid)
        return false;

    for (int i = 1; i < n; i++)
    {
        if (newArray[i - 1] < mid)
        {
            ll buffer = mid - newArray[i - 1];
            newArray[i - 1] = mid;
            newArray[i] = newArray[i] - buffer;
        }
        if (newArray[i] > mid)
        {
            return false;
        }
    }

    long long maxi = *max_element(newArray.begin(), newArray.end());
    if (maxi > mid)
    {
        return false;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        ll i = 0, j = *max_element(vec.begin(), vec.end()),ans = LONG_MAX;

        while (i <= j)
        {
            ll mid = i + (j - i) / 2;

            if (solve(n, vec, mid))
            {
                ans = min(ans, mid);
                j = mid - 1;
            }
            else
            { 
                i = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}