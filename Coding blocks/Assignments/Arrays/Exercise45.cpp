////////////////////// Playing with bits

// #include <iostream>
// using namespace std;

// int set_bit(int n)
// {
//     int set_bit = 0;
//     while (n > 0)
//     {
//         if (n & 1 == 1)
//         {
//             set_bit++;
//         }
//         n = n >> 1;
//     }
//     return set_bit;
// }

// int main()
// {
//     int t, a, b;
//     cin >> t;

//     while (t--)
//     {
//         int count = 0;
//         cin >> a >> b;
//         for (int i = a; i <= b; i++)
//         {
//             count += set_bit(i);
//         }
//         cout << count << endl;
//     }

//     return 0;
// }

////////////////////// Unique Number - 1

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     int *arr = new int[n];
//     int unique_no = 0;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         unique_no ^= arr[i];
//     }

//     cout << unique_no << endl;

//     delete[] arr;
//     return 0;
// }

////////////////////// Unique Number - 3

#include <iostream>
using namespace std;

int binary_decimal(int *arr)
{
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += arr[i] * p;
        p <<= 1;
    }
    return ans;
}

void unique_number(int *n, int len)
{
    int cnt[64] = {0};
    for (int i = 0; i < len; i++)
    {
        int pos = 0;
        int no = n[i];
        while (no > 0)
        {
            if ((no & 1) == 1)
            {
                cnt[pos]++;
            }
            pos++;
            no >>= 1;
        }
    }

    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
    }

    cout << binary_decimal(cnt) << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unique_number(arr, n);

    delete[] arr;

    return 0;
}