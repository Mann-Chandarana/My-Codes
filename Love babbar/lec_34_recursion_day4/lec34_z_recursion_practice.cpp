#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
// #include "bits/stdc++.h"
using namespace std;

void reverseString(string &s, int start)
{
    if (start >= s.length() / 2)
        return;

    swap(s[start], s[s.length() - 1 - start]);
    reverseString(s, start + 1);
}

string reverseString1(string s, int i)
{
    if (i >= s.length() / 2)
        return s;

    swap(s[i], s[s.length() - 1 - i]);

    return reverseString1(s, i + 1);
}

void printReverse(string &s, int &start)
{
    if (start >= s.length())
        return;

    printReverse(s, ++start);
    start--; // Because we have used pass by reference for pasing start.
    cout << s[start];
}

long long power(int &a, int b)
{
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}

long long powerUsingBinarySearch(int &a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    if (b & 1)
    {
        // return a * powerUsingBinarySearch(a, (b - 1));
        return a * powerUsingBinarySearch(a,  b/2) * powerUsingBinarySearch(a, (b - 1) / 2); // Here b/2 and (b-1)/2 are same. integer.
    }
    else
        return powerUsingBinarySearch(a, b / 2) * powerUsingBinarySearch(a, b / 2);
}

int main()
{
    // string s = "parth";
    // cout << s << endl;
    // reverseString(s,0);
    // cout << s << endl;

    // string s = "parth";
    // string s1 = reverseString1(s,0);
    // cout << s1 << endl;

    // string s1 = "abcd";
    // cout << s1 << endl;
    // int start = 0;
    // printReverse(s1,start);
    // cout << endl;

    // //power(a,b)
    // int a,b;
    // cin >> a >> b;
    // cout << power(a,b) << endl;

    // Power using binary search
    int a,b;
    cin >> a >> b;
    cout << powerUsingBinarySearch(a,b) << endl;
    cout << pow(a,b) << endl;

    // Homework: Create a power function that can take negative powers too.

    cout << endl
         << "Main end.." << endl;
    return 0;
}
