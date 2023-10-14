#include "bits/stdc++.h"
using namespace std;

int kthSmallestElement(int arr[], int n, int k) // O(N logK)
{
    if (k > n)
    {
        cout << "Cannot access that element as k is greater than n" << endl;
        return -1;
    }
    priority_queue<int> maxHeap;
    // priority_queue<int,vector<int>> maxHeap; // Is also a max heap.
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    return maxHeap.top();
}

int main()
{
    int arr[] = {3, 10, 4, 15, 20, 7};
    int n = 6;
    int k = 3;

    // sort(arr, arr + n); // O(N logN)
    // cout << arr[k - 1] << endl;

    cout << kthSmallestElement(arr, n, k) << endl;

    return 0;
}