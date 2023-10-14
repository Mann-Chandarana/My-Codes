#include "bits/stdc++.h"
using namespace std;

void printMaxHeap(priority_queue<pair<int, pair<int, int>>> maxHeap)
// Printing from bottom to top.
{
    if (maxHeap.empty())
        return;
    pair<int, int> topElePair = maxHeap.top().second;
    maxHeap.pop();
    printMaxHeap(maxHeap);
    cout << topElePair.first << " " << topElePair.second << endl;
}

void kClosestPointsToOrigin(int **arr, int x, int y, int k)
{
    // priority_queue<pair<float, int>> maxHeap;
    priority_queue<pair<int, pair<int, int>>> maxHeap; // first = dist and second = pair{point_x,point_y}.

    for (int i = 0; i < x; i++)
    {
        int dis = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
        maxHeap.push({dis, {arr[i][0], arr[i][1]}});
        if (maxHeap.size() > k)
            maxHeap.pop();
    }

    printMaxHeap(maxHeap);

    cout << maxHeap.empty() << endl;
}

int main()
{
    int x, y = 2;
    cin >> x;
    int **arr = new int *[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = new int[y];
    }

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> arr[i][j];

    int k;
    cin >> k;

    kClosestPointsToOrigin(arr, x, y, k);

    return 0;
}