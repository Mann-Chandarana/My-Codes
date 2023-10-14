// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

/*
    Deque is a combination of stack and queue.
    In deque, we can do operations like, push and pop from the end, insert and delete from the front.
*/

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    // dq.pop_front();
    // dq.pop_back();

    // cout << dq.front() << endl;
    // cout << dq.back() << endl;

    cout << dq.size() << endl;

    for (auto element : dq)
    {
        cout << element << " ";
    }

    return 0;
}