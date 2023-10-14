#include "bits/stdc++.h"
using namespace std;
#define ip pair<int, int>

void topKFrequencyNumbers(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    /*
        In map:
        1 -> 3
        2 -> 2
        3 -> 1
        4 -> 1
        first element in map is the element in the array, and second element of the map is the frequency of that element in the array.
        So, in minHeap we will add pairs where, second element of the will be the first element, as we want to sort using frequencies. 
    */
    for (int i = 0; i < n; i++)
    {
        // Default value is 0.
        mp[arr[i]]++;
    }

    priority_queue<ip, vector<ip>, greater<ip>> minHeap;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minHeap.push(make_pair(i->second, i->first));
        if (minHeap.size() > k)
            minHeap.pop();
    }

    // If we want to print with top frequency element first, then print the reverse of the minHeap.
    //  as its top is having the minimum value.So, max value would be at the bottom.
    while (!minHeap.empty())
    {
        cout << minHeap.top().second << endl;
        minHeap.pop();
    }
}

int main()
{
    int arr[] = {1, 2, 1, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    topKFrequencyNumbers(arr, n, k);

    return 0;
}