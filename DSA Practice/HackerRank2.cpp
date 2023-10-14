#include <iostream>
using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;
    int *arr;
    arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < R; i++)
    {
        int value = arr[0];
        for (int i = 0; i < N-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[N - 1] = value;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}

// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int N, d, i;
//     cin >> N >> d;
//     int start = N - d;
//     int *arr = new int[N];
//     for (i = 0; i < N; ++i)
//     {
//         if (start == N)
//             start = 0;
//         cin >> arr[start++];
//     }
//     for (i = 0; i < N; ++i)
//         cout << arr[i] << " ";
//     return 0;
// }