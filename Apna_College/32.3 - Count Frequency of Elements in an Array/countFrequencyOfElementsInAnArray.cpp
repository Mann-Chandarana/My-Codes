#include "bits/stdc++.h"
using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 1, 1, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> ump;
    // By default values are 0.

    for (int i = 0; i < n; i++)
        ump[arr[i]]++;

    for (auto i = ump.begin(); i != ump.end(); i++)
        cout << i->first << "  " << i->second << endl;

    cout << endl;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto i : mp)
        cout << i.first << "  " << i.second << endl;

    return 0;
}