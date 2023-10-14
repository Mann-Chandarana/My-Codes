#include "bits/stdc++.h"
using namespace std;

vector<int> frequencySort(int arr[], int n)
{
    // Problem with heap: o/p with heaps: 1 1 1 2 2 4 3
    // O/P should be: More frequenct elements first. If same frequency, then greater element first.
    // O/P: 1 1 1 2 2 3 4
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    priority_queue<pair<int, int>> maxHeap;

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxHeap.push({i->second, i->first});
    }

    while (!maxHeap.empty())
    {
        int temp = maxHeap.top().first;
        while (temp > 0)
        {
            cout << maxHeap.top().second << " ";
            temp--;
        }
        maxHeap.pop();
    }
}

int main()
{
    int arr[] = {1, 2, 1, 3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    frequencySort(arr, n);

    return 0;
}