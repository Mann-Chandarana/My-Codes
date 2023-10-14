#include <bits/stdc++.h>
using namespace std;

int join_ropes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);

    int cost = 0;

    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int new_ropes = A + B;
        cost += new_ropes;
        pq.push(new_ropes);
    }
    return cost;
}

int main()
{

    return 0;
}