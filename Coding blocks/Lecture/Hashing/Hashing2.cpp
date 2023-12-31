///////////// Longest subarray with sum 0

#include <bits/stdc++.h>
using namespace std;

int Longest_subarray_with_sum0(int *arr, int n)
{
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == 0)
        {
            len = max(len, i + 1);
        }
        if (m.find(pre) != m.end())
        {
            len = max(len, i - m[pre]);
        }
        else
        {
            m[pre] = i;
        }
    }
    return pre;
}

int main()
{

    return 0;
}