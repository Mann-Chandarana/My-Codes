#include <iostream>
#include <climits>
using namespace std;

//////// To find subarray and sum of maximum subarray
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int Maxsum = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int sum = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 sum+=arr[k];
//                 //cout << arr[k] << " ";
//             }
//             // cout << endl;
//             Maxsum=max(Maxsum,sum);
//         }
//     }
//     cout<<Maxsum<<endl;
//     return 0;
// }
///////// Another method to find sum of maximum subarray

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int currsum[n + 1];
    currsum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        currsum[i] = currsum[i - 1] + arr[i - 1];
    }
    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currsum[i] - currsum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum;

    return 0;
}