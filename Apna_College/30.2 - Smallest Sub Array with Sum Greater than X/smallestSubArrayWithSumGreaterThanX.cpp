#include "bits/stdc++.h"
using namespace std;

int smallestSubArraySize(int arr[], int n, int x) // O(N).
{
    int start = 0, end = 0, minLength = n + 1, sum = 0; // Here n is the maximum length possible. n + 1 would be infinity for this case.
    for (end = 0; end < n; end++)
    {
        sum += arr[end];
        if (sum > x) // Use >= is greater than or equal X is given.
        {
            while (start <= end and sum > x)
            {

                minLength = min(minLength, end - start + 1);
                sum -= arr[start];
                start++;
            }
        }
    }
    if (minLength == n + 1)
        return -1;
    return minLength;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << smallestSubArraySize(arr, n, x) << endl;

    return 0;
}