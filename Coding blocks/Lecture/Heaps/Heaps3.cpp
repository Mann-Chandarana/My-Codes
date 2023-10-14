////////////// Build Heap from an array

#include <bits/stdc++.h>
using namespace std;

bool minHeap = false;

bool compare(int a, int b)
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        a > b;
    }
}

void heapify(vector<int> v, int idx)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if (left <= last && compare(v[left], v[idx]))
    {
        min_idx = left;
    }
    if (right <= last && compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx);
    }
}
void BuildHeapOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main()
{

    return 0;
}