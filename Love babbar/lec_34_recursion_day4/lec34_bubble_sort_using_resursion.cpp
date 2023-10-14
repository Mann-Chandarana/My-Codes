#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n)
{
    // Base condition
    if (n == 0 or n == 1) // Array is already sorted
        return;

    bool check = true;

    // 1 case solve kar liya -> Largest element ko end mein pohacha denga
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            check = false;
        }
    }
    if(check) // If array is already sorted at this point, then retur. No need to go for another loop.
        return;
    // This check is not mendatory.

    // Recursive call
    bubbleSort(arr, n - 1);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print(arr, n);
    bubbleSort(arr, n);
    print(arr, n);

    return 0;
}