#include <iostream>
#include <queue>
using namespace std;
////////////////////////////////////////////
void kClosestElements(int *arr, int n, int k, int x)
{
    if (k > n)
    {
        cout << "Not possible" << endl;
        return;
    }
    priority_queue<pair<int, int>> maxHeap;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(make_pair(abs(arr[i] - x), arr[i]));
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    while (!maxHeap.empty())
    {
        p = maxHeap.top();
        cout << p.second << " ";
        maxHeap.pop();
    }
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3, x = 7;

    kClosestElements(arr, n, k, x);
    cout << endl;
    return 0;
}