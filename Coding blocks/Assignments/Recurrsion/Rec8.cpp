///////////////// Quick sort

#include <iostream>
#include <algorithm>
using namespace std;

int parition(int *a, int s, int e)
{
    int i = s - 1;

    for (int j = s; j < e; j++)
    {
        if (a[j] <= a[e])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void QuickSort(int *a, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int indx = parition(a, s, e);
    QuickSort(a, s, indx - 1);
    QuickSort(a, indx + 1, e);
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
    QuickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }

    delete[] arr;

    return 0;
}