#include "bits/stdc++.h"
using namespace std;

void heapify(int arr[], int n, int i)
{
    int maxIdx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n and arr[l] > arr[maxIdx])
        maxIdx = l;
    if (r < n and arr[r] > arr[maxIdx])
        maxIdx = r;

    if (maxIdx != i)
    {
        swap(arr[i], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}