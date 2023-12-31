#include "bits/stdc++.h"
using namespace std;

int findPeakElement(int arr[], int low, int high, int n)
{
    int mid = low + (high - low) / 2;
    // Sometimes (low + high) exceeds the range of int and can give errors.
    // low + (high - low) / 2 will stay withing the limits of int.

    if ((mid == 0 or arr[mid - 1] <= arr[mid]) and (mid == n - 1 or arr[mid + 1] <= arr[mid]))
    {
        return mid;
    }
    else if (mid > 0 and arr[mid - 1] > arr[mid])
    {
        return findPeakElement(arr, low, mid - 1, n);
    }
    else
        return findPeakElement(arr, mid + 1, high, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findPeakElement(arr, 0, n - 1, n);

    return 0;
}