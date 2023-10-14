#include <bits/stdc++.h>
using namespace std;

////////// Median in a running stream

int main()
{
    priority_queue<int> leftHeap;                             // MaxHeap
    priority_queue<int, vector<int>, greater<int>> rightHeap; // MinHeap

    int d;
    cin >> d;
    leftHeap.push(d);

    float med = d;
    cout << "Median " << med << " ";
    cin >> d;
    // Input all elements
    while (d != -1)
    {
        // logic
        if (leftHeap.size() > rightHeap.size())
        {
            if (d < med)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if (leftHeap.size() == rightHeap.size())
        {
            if (d < med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else
            {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }
        else
        {
            if (d > med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                leftHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }

        cout << "Med " << med << endl;
        cin >> d;
    }

    return 0;
}