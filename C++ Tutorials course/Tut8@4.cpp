#include <iostream>
using namespace std;

///////// Max Value problem
// int main()
// {
//     int mx = 0;
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         mx = max(mx, arr[i]);
//         cout << mx << endl;
//     }

//     return 0;
// }

///////// Subarray and Subsequences
// Subarray = nc2+n
// Subsequences = 2^n

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int curr = 0;
//     for (int i = 0; i < n; i++)
//     {
//         curr = 0;
//         for (int j = i; j < n; j++)
//         {
//             curr += a[j];
//             cout << curr << endl;
//         }
//     }

//     return 0;
// }