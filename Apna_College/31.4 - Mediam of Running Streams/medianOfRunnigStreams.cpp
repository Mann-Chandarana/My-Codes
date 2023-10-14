#include "bits/stdc++.h"
using namespace std;

priority_queue<int, vector<int>> pqMax;
priority_queue<int, vector<int>, greater<int>> pqMin;

void insert(int n)
{
    if (pqMax.size() == pqMin.size())
    {
        if (pqMax.size() == 0)
        {
            pqMax.push(n);
            return;
        }
        if (n < pqMax.top())
        {
            pqMax.push(n);
            return;
        }
        else
        {
            pqMin.push(n);
            return;
        }
    }
    else
    {
        if (pqMax.size() > pqMin.size())
        {
            if (n >= pqMax.top())
            {
                pqMin.push(n);
                return;
            }
            else
            {
                int temp = pqMax.top();
                pqMax.pop();
                pqMin.push(temp);
                pqMax.push(n);
                return;
            }
        }
        else
        {
            if (n <= pqMin.top())
            {
                pqMax.push(n);
                return;
            }
            else
            {
                int temp = pqMin.top();
                pqMin.pop();
                pqMax.push(temp);
                pqMin.push(n);
            }
        }
    }
}

double findMedian()
{
    if (pqMax.size() == pqMin.size())
        return (pqMax.top() + pqMin.top()) / 2.0;
    else
    {
        if (pqMax.size() > pqMin.size())
            return pqMax.top();
        else
            return pqMin.top();
    }
}

int main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;


    return 0;
}