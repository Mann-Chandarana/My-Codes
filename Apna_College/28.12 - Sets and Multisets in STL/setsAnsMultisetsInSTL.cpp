#include "bits/stdc++.h"
using namespace std;

// Values of the set cannot be modified.
// We can only add and remove the elements.

// Time complexity 
// Insertion and Deletion: O(Log N)
// Upper and Lower bound: O(Log N)

int main()
{
    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2); // Sets don't contain duplicate elements.
    // s.insert(3);
    //
    // cout << s.size() << endl;
    //
    // for (auto i : s)
    //     cout << i << " ";
    // cout << endl;
    //
    // for (auto i = s.begin(); i != s.end(); i++)
    //     cout << *i << " ";
    // cout << endl;
    //
    // // Reverse traversal.
    // for (auto i = s.rbegin(); i != s.rend(); i++)
    //     cout << *i << " ";
    // cout << endl;
    //
    // cout << *s.lower_bound(0) << endl; // >= 0
    // cout << *s.upper_bound(1) << endl; // > 1
    // if (s.upper_bound(3) == s.end())
    //     cout << "This is the last element of the set." << endl;

    // // Custom comparator.
    // set<int, greater<int>> s1;
    // s1.insert(3);
    // s1.insert(4);
    // s1.insert(5);
    // s1.insert(2);
    //
    // for (auto i : s1)
    //     cout << i << " ";
    // cout << endl;

    // set<int> s2;
    // s2.insert(1);
    // s2.insert(3);
    // s2.insert(2);
    // s2.insert(5);
    // s2.erase(2);
    // s2.erase(s2.begin()); // We can also give the value: s2.erase(*s2.begin()).
    //
    // // s2.erase(s2.begin(), s2.end()); // We can erase entire set also.
    // for (auto i : s2)
    //     cout << i << " ";
    // cout << endl;

    /*
        MultiSets: They can contain duplicates.
    */

    multiset<int> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(4);
    ms.insert(2);
    ms.insert(2);

    for (auto i : ms)
        cout << i << " ";
    cout << endl;

    if (ms.find(12) != ms.end())
        cout << "Is present" << endl;
    else
        cout << "Is not present" << endl;

    // All the operations are same as sets.

    // ms.erase(2); // All the ocurrence of 2 will be erased.
    // If we want to erase only one 2.
    ms.erase(ms.find(2));

    for (auto i : ms)
        cout << i << " ";
    cout << endl;


    return 0;
}