/////////// Find the Kth largest element

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(v[i]);

        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    cout << minHeap.top() << endl;

    return 0;
}