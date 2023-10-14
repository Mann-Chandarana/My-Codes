////////////////////// Array target sum triplet

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, *arr, target;
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> target;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int temp = target - arr[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            if (arr[left] + arr[right] > temp)
            {
                right--;
            }
            else if (arr[left] + arr[right] < temp)
            {
                left++;
            }
            else
            {
                cout << arr[i] << ", " << arr[left] << " and " << arr[right] << endl;
                left++;
                right--;
            }
        }
    }

    delete (arr);

    return 0;
}