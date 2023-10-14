#include "bits/stdc++.h"
using namespace std;

int kthLargestElement(int arr[], int n, int k)
{
    if (k > n)
    {
        cout << "Cannot access that element as k is greater than n" << endl;
        return -1;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
            minHeap.pop();
    }

    return minHeap.top();
}

int main()
{
    int arr[] = {3, 10, 4, 15, 20, 7};
    int n = 6;
    int k = 2;

    cout << kthLargestElement(arr, n, k) << endl;

    return 0;
}