#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int t, p, balance;
    cin >> t;

    while (t--)
    {
        cin >> p;
        int arr[p];

        for (int i = 0; i < p; i++)
        {
            cin >> arr[i];
        }

        cin >> balance;
        sort(arr, arr + p);

        int left = 0, right = p - 1;
        int mini = INT_MAX, x, y;

        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == balance)
            {
                if (arr[right] - arr[left] < mini)
                {
                    mini = arr[right] - arr[left];
                    x = left;
                    y = right;
                }
                left++;
                right--;
            }
            else if (sum > balance)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        cout << "Deepak should buy roses whose prices are " << arr[x] << " and " << arr[y] << "." << endl;
    }

    return 0;
}