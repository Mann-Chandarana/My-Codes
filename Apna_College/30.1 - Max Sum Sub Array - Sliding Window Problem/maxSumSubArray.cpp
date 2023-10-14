#include "bits/stdc++.h"
using namespace std;

// Find sub arrays of size k, sum of that sub array should be maximum and less than x.

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k, x;
    cin >> k >> x;
    int sum = 0, ans = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
        ans = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i]; // i - k is start pointer.
        if (sum < x and sum > ans)
            ans = sum;
    }

    cout << ans << " is the sum of sub array with maximum sum (sum < " << x << ")" << endl;

    return 0;
}