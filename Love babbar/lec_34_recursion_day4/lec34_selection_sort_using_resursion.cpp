#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void selectionSort(int *arr, int n)
{
    if (n == 0 or n == 1)
        return;

    int minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[minIdx]) // <= is taken for same elements case.
            minIdx = i;
    }
    if (minIdx == 0) // Array is already sorted
        return;
    swap(arr[minIdx], arr[0]);

    selectionSort(arr + 1, n - 1);
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
    selectionSort(arr,n);
    print(arr,n);


    return 0;
}