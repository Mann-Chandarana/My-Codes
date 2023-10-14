#include "bits/stdc++.h"
using namespace std;

int main()
{
    // Ordered Maps:
    // map<key, value> map_name;
    map<int, int> m;

    m[8] = 2;
    m[2] = 4;
    m[-2] = 19;
    // In ordered maps, data is stored in ascending values of keys.
    // cout << m[8] << endl;

    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->second << " ";
    cout << endl;

    // Unordered Maps:
    // unordered_map<key, value> map_name;
    // In unordered map, order is not set.
    unordered_map<int, int> ump;
    ump[8] = 2;
    ump[2] = 4;
    ump[-1] = 19;

    for (auto it : m)
        cout << it.second << " ";
    cout << endl;

    return 0;
}