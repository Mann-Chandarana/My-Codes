#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

void heapifyy(vector<int> &v, int idx)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if (left <= last && compare(v[left], v[min_idx]))
    {
        min_idx = left;
    }

    if (right <= last && compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapifyy(v, min_idx);
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

void buildOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapifyy(v, i);
    }
}

void heapify_For_Sort(vector<int> &v, int idx,int Size)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = Size - 1;

    if (left <= last && compare(v[left], v[min_idx]))
    {
        min_idx = left;
    }

    if (right <= last && compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify_For_Sort(v, min_idx,Size);
    }
}

void heapsort(vector<int> &v)
{
    buildHeap(v);
    int n = v.size();

    while (n > 1)
    {
        swap(v[1], v[n - 1]);
        n--;
        heapify_For_Sort(v, 1, n);
    }
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 8, 9, 4};
    buildOptimised(v);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}