#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> arr(2 * n);

        for (int i = 0; i < 2 * n; i++)
        {
            int element;
            cin >> element;
            arr[i] = element;
        }

        sort(arr.begin(), arr.end());

        int mini = arr[n - 1] - arr[0];

        for (int i = 1; i <= n; i++)
        {
            mini = min(mini, arr[i + n - 1] - arr[i]);
        }

        cout << mini << endl;
    }

    return 0;
}