///////////// Longest subarray with sum k

#include <bits/stdc++.h>
using namespace std;

int Longest_subarray_with_sum_K(int *arr, int n,int k)
{
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == k)
        {
            len = max(len, i + 1);
        }
        if (m.find(pre-k) != m.end())
        {
            len = max(len, i - m[pre-k]);
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