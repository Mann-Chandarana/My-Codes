#include <bits/stdc++.h>
using namespace std;

#define printArr(arr, n)        \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;

// heap sort is done based on 0 based indexing of the heap.
// arr[0] is not -1 (dummy)

void heapify(int *arr, int n, int idx)
{
    int largest = idx;
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;

    if (leftIdx < n and arr[largest] < arr[leftIdx])
        largest = leftIdx;
    if (rightIdx < n and arr[largest] < arr[rightIdx])
        largest = rightIdx;

    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);
        heapify(arr, n, largest);
    }
}

void createHeap(int *arr, int n)
{
    // Beacause of 0 based indexing
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int *arr, int n)
{
    // Step 1: Create a max heap from given array
    createHeap(arr, n);

    int size = n;
    while (size > 1)
    {
        // Step 2: swap last element with root
        swap(arr[0], arr[size - 1]);
        size--;
        // Step 3: Take the root to its correct position
        heapify(arr, size, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    printArr(arr, n);
    heapSort(arr, n);
    printArr(arr, n);

    return 0;
}