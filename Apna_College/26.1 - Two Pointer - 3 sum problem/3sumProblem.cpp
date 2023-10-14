// #include <iostream>
#include "bits/stdc++.h"
#include<vector>
using namespace std;
// O(n^2)
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    bool found = false;
    sort(a.begin(), a.end()); // O(n*logn)
    for (int i = 0; i < n; i++) // O(n^2)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int current = a[i] + a[low] + a[high] ;
            if (current == target)
            {
                found = true;
                break;
            }
            if (current < target)
            {
                low++;
            }
            if (current > target)
            {
                high--;
            }
        }
    }

    if (found)
    {
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;

    return 0;
}