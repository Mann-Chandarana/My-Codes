////////////// Heap sort

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

void heapify(vector<int> v, int idx,int size)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = size - 1;

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
        heapify(v, min_idx,size);
    }
}

void heapsort(vector<int> &arr)
{
    buildHeap(arr);
    int n = arr.size();

    // Remove n-1 elements from the heap
    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);

        // remove that element from the heap
        n--;
        heapify(arr, 1, n);
    }
}
void buildHeap(vector<int> &v)
{
    for (int i = 2; i < v.size(); i++)
    {
        int idx = i;
        int parent = i / 2;
        while (idx > 1 && v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

int main()
{

    return 0;
}