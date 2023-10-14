// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

void printMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap)
{
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>> maxheap2;
    // we can leave vector<int> container for max heap, but it is necessary to include vector<int> container for min heap.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    if (maxHeap.empty()) ////////////////////
        cout << "Max heap is empty\n";

    maxHeap.push(1); ///////////////////////
    maxHeap.push(3);
    maxHeap.push(2);

    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;

    cout << endl;

    minHeap.push(5);
    minHeap.push(9);
    minHeap.push(1);
    minHeap.push(4);

    cout << minHeap.top() << endl; //////////////////////////
    cout << "Min heap size: " << minHeap.size() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap2;
    minHeap2.emplace(20); /////////////////////////////
    minHeap2.emplace(10);

    cout << "Min heap2 size: " << minHeap.size() << endl;

    cout << "Before swap: " << endl;
    cout << "min heap1: ";
    printMinHeap(minHeap);
    cout << "min heap2: ";
    printMinHeap(minHeap2);

    minHeap.swap(minHeap2); //////////////////////////

    cout << "After swap: " << endl;
    cout << "min heap1: ";
    printMinHeap(minHeap);
    cout << "min heap2: ";
    printMinHeap(minHeap2);


    return 0;
}