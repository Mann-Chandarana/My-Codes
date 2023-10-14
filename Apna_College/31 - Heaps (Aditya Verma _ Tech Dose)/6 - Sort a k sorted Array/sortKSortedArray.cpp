#include "bits/stdc++.h"
using namespace std;
// Nearly sorted array.
// Important Question

//// Complexity nlogk

void sortKSortedArray(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            arr[i - k] = minHeap.top();
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        // Here arr[n - minHeap.size()] is for all the values of k greater than minimum k. k can be greater the n in this case.
        arr[n - minHeap.size()] = minHeap.top();
        minHeap.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    sortKSortedArray(arr, n, k);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}