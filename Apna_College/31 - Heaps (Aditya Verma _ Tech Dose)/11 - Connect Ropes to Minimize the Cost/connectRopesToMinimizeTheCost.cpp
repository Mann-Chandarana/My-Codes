#include "bits/stdc++.h"
using namespace std;

int minCost(int arr[], int n)
{
    // Add the minimum ropes and cost.
    // Explanation in notes.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    int totalCost = 0;
    while (true)
    {
        int top1 = minHeap.top();
        minHeap.pop();
        int top2 = minHeap.top();
        minHeap.pop();
        totalCost += (top1 + top2);

        if (minHeap.empty())
            break;
        minHeap.push(top1 + top2);
    }

    return totalCost;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // Elements in the array represent the length of each ropes.
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minCost(arr, n) << endl;

    return 0;
}