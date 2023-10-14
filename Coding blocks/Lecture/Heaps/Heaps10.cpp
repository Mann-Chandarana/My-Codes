///// Merge K sorted array

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKsortedArrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // min Priority queue

    // insert the 0th element of every array in the pq

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }

    // remove the elements one by one from the min heap and add to result vector
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;  // row in which element present
        int y = current.second.second; // col in which element present

        result.push_back(element);

        // you nedd to push PQ the next element of current element x,y+1
        if (y + 1 < arr[x].size())
        {
            pq.push({element, {x, y + 1}});
        }
    }
    return result;
}

int main()
{

    return 0;
}