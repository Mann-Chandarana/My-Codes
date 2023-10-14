#include "bits/stdc++.h"
using namespace std;

set<vector<int>> set_of_vec;

void printVec(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> vec_1 = {10, 20, 30, 40};
    vector<int> vec_2{5, 10, 15};
    vector<int> vec_3{1, 3, 5, 7, 9, 11, 13};
    vector<int> vec_4{5, 10, 15};
    vector<int> vec_5{10, 20, 30, 40};

    set_of_vec.insert(vec_1);
    set_of_vec.insert(vec_2);
    set_of_vec.insert(vec_3);
    set_of_vec.insert(vec_4);
    set_of_vec.insert(vec_5);

    cout << "Set of vectors: \n";
    for (auto i : set_of_vec)
        printVec(i);

    cout << endl;

    cout << "Using iterator: \n";
    for (auto i = set_of_vec.begin(); i != set_of_vec.end(); i++)
        printVec(*i);

    return 0;
}