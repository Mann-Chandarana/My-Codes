#include "bits/stdc++.h"
using namespace std;

bool isFeasible(int boards[], int n, int limit, int totalPintersAvailable)
{
    int sum = 0, paintersRequired = 1;
    for (int i = 0; i < n; i++)
    {
        if (boards[i] > limit)
            return false;
        if (sum + boards[i] > limit)
        {
            sum = boards[i];
            paintersRequired++;
        }
        if (paintersRequired > totalPintersAvailable)
            return false;
        else
            sum += boards[i];
    }

    return true;
}

int paintersPartions(int boards[], int n, int m)
{
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }
    // Here we are giving k to low istead of boards[0].
    // We can also give boards[0].
    // But for one painter from total painters, the minimum time to paint would be maximum element from that boards array.
    int low = k, high = totalLength, res = -1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(boards, n, mid, m))
        {
            high = mid;
            res = mid;
        }
        else
            low = mid + 1;
    }
    return res; // Minimum time for painters to paint a block.
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    // Sorted array required. Binary Search method is used.
    int n = 4;
    int m = 2;

    cout << "Minimum time to paint boards: " << paintersPartions(arr, n, m) << endl;

    return 0;
}