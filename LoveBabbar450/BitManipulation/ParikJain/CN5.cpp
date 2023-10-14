#include <bits/stdc++.h>
using namespace std;

/* O(N*log(w)) */

int countDistinctBitwiseOR(vector<int> &inputVector, int size)
{
    vector<int> res;
    unordered_set<int> ans;

    int left = 0, right;

    for (int a : inputVector)
    {
        right = res.size();
        res.push_back(a);
        for (int i = left; i < right; i++)
        {
            if (res.back() != (res[i] | a))
            {
                res.push_back(res[i] | a);
            }
        }
        left = right;
    }

    for (int i = 0; i < res.size(); i++)
        ans.insert(res[i]);

    return ans.size();
}

/* O(N^2) */

// int countDistinctBitwiseOR(vector<int> &inputVector, int size)
// {
//     int var = 0;

//     set<int> ans;

//     for (int i = 0; i < size; i++)
//     {
//         var = 0;
//         for (int j = i; j < size; j++)
//         {
//             var = var | inputVector[j];
//             ans.insert(var);
//         }
//     }
//     return ans.size();
// }

int main()
{
    return 0;
}