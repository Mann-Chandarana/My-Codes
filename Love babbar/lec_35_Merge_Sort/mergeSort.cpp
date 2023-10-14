#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeUsingTempArr(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *leftArr = new int[len1];
    int *rightArr = new int[len2];

    // Copy values
    int k = start; // IMP
    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[k++];

    // if(k == mid + 1) cout << "YES" << endl; // k is same (mid + 1)
    k = mid + 1;
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[k++];

    // Merge2 sorted array
    int i = 0, j = 0;
    int idx = start; // IMP
    while (i < len1 and j < len2)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[idx++] = leftArr[i++];
        }
        else
            arr[idx++] = rightArr[j++];
    }

    while (i < len1)
    {
        arr[idx++] = leftArr[i++];
    }

    while (j < len2)
    {
        arr[idx++] = rightArr[j++];
    }

    // We have given dynamic memory allocation. So, we need to delete them to avoid memory leak.
    delete[] leftArr;
    delete[] rightArr;
}
/*
void mergeWithoutAnyTempArr(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int i = start, j = mid + 1;

    while (i <= mid)
    {
        if (arr[j] < arr[i])
        {
            swap(arr[i++], arr[j]);
        }
        else
            i++;
        for (int k = mid + 1; k < end; k++)
        {
            if (arr[k] > arr[k + 1])
                swap(arr[k], arr[k + 1]);
            else
                break;
        }
    }

    while (j < end)
    {
        if (arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
        else
            break;
        j++;
    }
}
*/

void mergeSort(int *arr, int start, int end)
{
    // Base condition
    if (start >= end) // >= is used, because if start == end, then only one element is there, and it is already sorted.
        return;

    int mid = start + (end - start) / 2;

    // Merge sort: Solve left part and solve right part and then merge them.

    // Solve left part
    mergeSort(arr, start, mid);

    // Solve right part
    mergeSort(arr, mid + 1, end);

    // merge both parts
    mergeUsingTempArr(arr, start, end);

    // mergeWithoutAnyTempArr(arr,start,end); // Errors.
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print(arr, n);
    mergeSort(arr, 0, n - 1);
    print(arr, n);

    cout << "Main end.." << endl;
    delete[] arr;
    return 0;
}