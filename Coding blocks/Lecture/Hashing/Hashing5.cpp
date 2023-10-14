///////// Longest consective subsequence

#include <bits/stdc++.h>
using namespace std;

//////////  ------>  third approach using sets

int largest_sequence(int *arr, int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]); // O(1)
    }
    int max_streak = 1;
    ////// iterate over all the element
    ////// largest those from which a streak can start

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int next_no = arr[i] + 1;
            int streak_len = 1;
            while (s.find(next_no) != s.end())
            {
                next_no += 1;
                streak_len++;
            }
            max_streak = max(max_streak, streak_len);
        }
    }
    return max_streak;
}

int main()
{

    return 0;
}