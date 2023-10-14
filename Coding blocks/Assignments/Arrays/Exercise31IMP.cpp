////////////////////// Rain water trapping

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t, N;
    cin >> t;

    while (t--)
    {
        cin >> N;
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int *left = new int[N];
        int *right = new int[N];

        int maxi = INT_MIN, sum = 0;
        left[0] = arr[0];
        for (int i = 1; i < N; i++)
        {
            left[i] = max(left[i - 1], arr[i]);
        }
        right[N - 1] = arr[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], arr[i]);
        }

        for (int i = 0; i < N; i++)
        {
            sum += (min(left[i], right[i]) - arr[i]);
        }

        cout << sum << endl;

        delete (arr);
        delete (left);
        delete (right);
    }

    return 0;
}