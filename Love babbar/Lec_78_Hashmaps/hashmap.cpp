#include <bits/stdc++.h>
using namespace std;

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for(int i=0;i<n;i++)cout << arr[i] << " "; cout << endl;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
*/

void unOrderedMap()
{
    // map<key, value>
    // Key are unique in map
    // Single entry for a key
    // <"Parth", 3> and <"Parth", 4> cannot exist together

    // Declaration
    unordered_map<string, int> m;

    // Insertion using pair
    pair<string, int> p = make_pair("Parth", 4);
    m.insert(p);
    p.first = "Niraj";
    p.second = 6;
    m.insert(p);

    // Insertion using key
    m["Mann"] = 5;
    m["Mann"] = 10;
    m["Malav"];

    cout << "Printing value of a key" << endl;
    cout << m["Mann"] << endl;
    cout << m.at("Parth") << endl;
    auto it1 = m.find("Niraj");
    cout << it1->first << " " << it1->second << endl;
    cout << m["abcd"] << endl; // Would print 0.
    // Why? abcd is not already present. But when we try to access it, map automatically creates a pair with value as 0.
    // cout << m.at("xyz") << endl; // Would give error

    // auto it1 = m.find("Nirajasdasdasd");
    // cout << it1->first << " " << it1->second << endl;
    // Error, Nirajasdasdasd is not there in map.
    // Trying to acces first and second of an iterator which is pointing to the end() would give error

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Removing a key from map
    m.erase("abcd");

    // Iteration using auto iterator
    cout << "Printing entire map table" << endl;
    for (auto ele : m)
        cout << ele.first << " " << ele.second << endl;

    // Size
    cout << m.size() << endl;

    ///////////////////////////////////////
    cout << "Use of count function" << endl;
    cout << m.count("xyz") << endl;
    cout << m.count("Parth") << endl;
    cout << m.count("Niraj") << endl;
    // Working of count function: return m.find(key) == m.end() ? 0 : 1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Creation of iterator of type unordered_map
    unordered_map<string, int>::iterator it;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // map.find(key) function
    // Returns the iterator at which the key is at. If key not found, return map.end()
    if (m.find("Harsh") == m.end())
        cout << "Not found" << endl;
    if (m.find("Niraj") != m.end())
        // distance function(map.begin(), iterator) returns the distance between these two
        // Condition: first argument should be the iterator that comes first
        // distance(m.find("Niraj"), m.begin()) would give error
        cout << "Found at " << distance(m.begin(), m.find("Niraj")) << endl;

    // cout << distance(m.find("Malav"), m.end()) << endl; // No error
    // cout << distance(m.find("Malavasdad"), m.end()) << endl; // 0, because Malavasdad is not present in the map

    for (it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;

    // map.clear() clears the entire map
    m.clear();
    cout << m.size() << endl;
    if (m.empty())
        cout << "Empty" << endl;
}

void mapFunction()
{
    // A map is based on BST.

    map<string, int> m;
    m["Parth"] = 1;
    m["Zues"] = 12;
    m["Part"] = 1000;
    m["Niraj"] = 10;
    m["Ahuti"] = 12;
    m["Mann"] = 100;

    for (auto ele : m)
        cout << ele.first << " " << ele.second << endl;
    // All elemetns in map are in sorted form based on there key

    // All other operations are similar as unordered map
}

int main()
{
    // // unoredered_map<key, value>
    // unOrderedMap();

    // amp<key, value>
    mapFunction();

    return 0;
}