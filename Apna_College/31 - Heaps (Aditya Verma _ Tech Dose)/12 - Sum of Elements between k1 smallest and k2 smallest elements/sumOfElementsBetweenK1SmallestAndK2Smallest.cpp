#include "bits/stdc++.h"
using namespace std;

int kthSmallestElement(int arr[], int n, int k) // O(N log k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}

int sumOfElementsBetweenK1ANdK2(int arr[], int n, int k1, int k2) //O( N log(max(k1,k2)) )
{
    if (k1 > k2)
        swap(k1, k2);
    else if (k1 == k2)
    {
        cout << "Can't find elements as k1 is same as k2 ";
        return -1;
    }
    int first = kthSmallestElement(arr, n, k1);
    int second = kthSmallestElement(arr, n, k2);

    int sum = 0;
    for (int i = 0; i < n; i++) // O(N)
    {
        if (arr[i] > first and arr[i] < second)
            sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Approach 1: Sort the array. add elements if(i > (small k1) and i < (big k2));
    // Time Complexity: O(N logN)

    // Approach 2: Using heaps. Find k1th smallest element and its index and same for k2 smallest and its index.
    // And then traverse the unsorted array and add the elements if element is greater than k1/k2 smallest (whichever from k1 and k2 is samaller)
    // and is smaller tha k1/k2 smallest.
    // Time Complexity: O(N log(max(k1,k2)) )

    // For approach 2.
    int k1 = 3, k2 = 6;
    // Here 3rd smallest if 5 and 6th smallest 15.

    cout << sumOfElementsBetweenK1ANdK2(arr, n, k2, k1) << endl;

    return 0;
}