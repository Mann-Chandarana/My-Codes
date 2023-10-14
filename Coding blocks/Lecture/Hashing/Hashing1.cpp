/////////////// Subarray whith sum = 0

#include <bits/stdc++.h>
using namespace std;

bool checkSum(int *arr, int n)
{
    unordered_set<int> s;
    int pre = 0;

    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == 0 or s.find(pre) != s.end())
        {
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main()
{

    return 0;
}