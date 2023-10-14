/////////// Merge k sorted arrays

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> node;

vector<int> mergeKsortedArray(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;

        result.push_back(element);
        if ((y + 1) < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    int n, k, element;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(k, 0));
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> element;
            v[i][j] = element;
        }
    }
    ans = mergeKsortedArray(v);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }

    return 0;
}