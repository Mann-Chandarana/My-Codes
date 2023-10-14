#include "bits/stdc++.h"
using namespace std;

int sizeOfSmallestSubSeq(int arr[], int n, int k)
{
    priority_queue<int, vector<int>> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }

    int sum = 0, count = 0;
    while (!maxHeap.empty())
    {
        sum += maxHeap.top();
        count++;
        maxHeap.pop();
        if (sum >= k)
            break;
    }
    if (sum < k)
        return -1;
    return count;
}

int main()
{
    int arr[] = {1, 1, 2, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 11;

    cout << sizeOfSmallestSubSeq(arr, n, k) << endl;

    return 0;
}