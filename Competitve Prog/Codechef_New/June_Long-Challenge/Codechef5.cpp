////////////////// reversal sorting

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t, n, x;
    cin >> t;

    while (t--)
    {
        cin >> n >> x;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool isCorrect = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                if (arr[i] + arr[i + 1] > x)
                {
                    cout << "NO" << endl;
                    isCorrect = false;
                    break;
                }
                else
                {
                    swap(arr[i], arr[i + 1]);
                }
            }
        }

        
        if (isCorrect)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}