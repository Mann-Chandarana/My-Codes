#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long *arr = new long[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        long answer = (arr[n - 1] - arr[0]) * arr[n - 2];

        cout << answer << endl;
    }

    return 0;
}