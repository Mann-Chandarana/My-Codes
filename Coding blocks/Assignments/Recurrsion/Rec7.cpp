////////////////// Merge sort

#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1, len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int k = s; // Important
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    int it1 = 0, it2 = 0;
    int it = s;

    while (it1 < len1 and it2 < len2)
    {
        if (arr1[it1] < arr2[it2])
        {
            arr[it++] = arr1[it1++];
        }
        else
            arr[it++] = arr2[it2++];
    }
    while (it1 < len1)
    {
        arr[it++] = arr1[it1++];
    }
    while (it2 < len2)
    {
        arr[it++] = arr2[it2++];
    }
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}