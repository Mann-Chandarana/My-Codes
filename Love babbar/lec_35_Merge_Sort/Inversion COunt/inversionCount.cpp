#include <bits/stdc++.h>
using namespace std;

/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted.
If the array is already sorted, then the inversion count is 0,
but if the array is sorted in the reverse order, the inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
*/

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;

    for (int i = 0; i < len1; i++)
        first[i] = arr[k++];

    k = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = arr[k++];

    int i = 0, j = 0;
    int count = 0;
    k = start;

    while (i < len1 and j < len2)
    {
        if (first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
            count += (len1 - i); // To count inversions.
        }
    }
    while (i < len1)
        arr[k++] = first[i++];

    while (j < len2)
        arr[k++] = second[j++];

    return count;
}

int inversionCount(int *arr, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    int count = 0;

    count += inversionCount(arr, start, mid);
    count += inversionCount(arr, mid + 1, end);

    count += merge(arr, start, end);

    // This code will sort the array. If we don't want the sorted array, then make a copy of that array and pass the copy. 

    return count;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print(arr, n);
    cout << inversionCount(arr, 0, n - 1) << endl;
    print(arr, n);

    return 0;
}