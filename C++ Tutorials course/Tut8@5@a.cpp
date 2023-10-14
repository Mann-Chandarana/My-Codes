#include <iostream>
using namespace std;

////// Subarray with given sum
// int main()
// {
//     int n, s;
//     cin >> n >> s;

//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int i = 0, j = 0, st = -1, en = -1, sum = 0;
//     while (j < n && sum + a[j] <= s)
//     {
//         sum += a[j];
//         j++;
//     }
//     if (sum == s)
//     {
//         cout << i + 1 << " " << j << endl;
//         return 0;
//     }
//     while (j < n)
//     {
//         sum += a[j];
//         while (sum > s)
//         {
//             sum -= a[i];
//             i++;
//         }
//         if (sum == s)
//         {
//             st = i + 1;
//             en = j + 1;
//             break;
//         }
//         j++;
//     }
//     cout << st << " " << en << endl;

//     return 0;
// }

////// Smallest positive missing number
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            check[a[i]] = true;
        }
    }
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}