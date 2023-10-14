///////////////// Is array sorted

#include <iostream>
using namespace std;

bool isSorted(int *arr, int n)
{
    if (n == 0)
    {
        return true;
    }
    if (arr[0] <= arr[1])
    {
        return isSorted(arr + 1, n - 1);
    }
    else
    {
        return false;
    }
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


    if (isSorted(arr, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    delete[] arr;
    return 0;
}