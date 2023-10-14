///////// Longest consective subsequence
/////   1) Sorting
/////   2) Hashing
/////   2) set

//////////  ------>  Second approach using maps

#include <bits/stdc++.h>
using namespace std;

int findlargestsub(int *arr, int n)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int no = arr[i];

        if (m.count(no - 1) == 0 and m.count(no + 1) == 0)
        {
            m[no] = 1;
        }
        if (m.count(no - 1) and m.count(no + 1))
        {
            int len1 = m[no - 1];
            int len2 = m[no + 1];

            int streak = len1 + len2 + 1;
            m[no - len1] = streak;
            m[no + len2] = streak;
        }
        else if (m.count(no - 1) and !m.count(no + 1))
        {
            int len = m[no - 1];
            m[no - len] = len + 1;
            m[no] = len + 1;
        }
        else
        {
            int len = m[no + 1];
            m[no + len] = len + 1;
            m[no] = len + 1;
        }
    }
    int largest = 0;
    for (auto p : m)
    {
        largest - max(largest, p.second);
    }
    return largest;
}

int main()
{

    return 0;
}