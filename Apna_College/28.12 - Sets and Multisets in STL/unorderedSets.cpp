#include "bits/stdc++.h"
using namespace std;

// Time complexity:
// Insertion and Deletetion: O(1) in avg case, O(N) in worst case.
// Lower and Upper bound: NA.

int main()
{
    unordered_set<int> us;

    us.insert(120);
    us.insert(12);
    us.insert(1);
    us.insert(5);
    us.insert(20);
    us.insert(2);
    us.insert(5); // Cannot contain duplicates.

    for (auto i : us)
        cout << i << " "; // Order is not set.
    cout << endl;

    // All other operations are same as sets and multisets.

    return 0;
}