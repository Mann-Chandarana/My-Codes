#include <iostream>
#include <climits>
using namespace std;
// kadane algorithm
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int currentSum = 0;
//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         currentSum += arr[i];
//         if (currentSum < 0)
//         {
//             currentSum = 0;
//         }
//         maxSum = max(maxSum, currentSum);
//     }
//     cout << maxSum << endl;

//     return 0;
// }

// Maximum Circular Subarray Sum
// Max subarray sum = Total sum of array - Sum of non-contributing elements
int kadane(int arr[], int n)
{
    int currentsum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentsum += arr[i];
        if (currentsum < 0)
        {
            currentsum = 0;
        }
        maxSum = max(maxSum, currentsum);
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int wrapsum;
    int nowrapsum;

    nowrapsum = kadane(arr, n);
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + kadane(arr, n);
    cout << max(wrapsum, nowrapsum) << endl;

    return 0;
}