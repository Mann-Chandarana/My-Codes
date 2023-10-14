#include <bits/stdc++.h>
using namespace std;

int main()
{
    // If length is n => total elements in power set are 2^n

    // if n = 3 => 8 elements
    /*
        if string is "abc"
        Binary representation of 0 -> 7 (n - 1)
          | 2 1 0 -> Index
        __|_______________
        0 | 0 0 0 => ""
        1 | 0 0 1 => "a"
        2 | 0 1 0 => "b"
        3 | 0 1 1 => "ab"
        4 | 1 0 0 => "c"
        5 | 1 0 1 => "ac"
        6 | 1 1 0 => "bc"
        7 | 1 1 1 => "abc"

        // 0 indicates taken and 1 indicates not taken.
    */

    // int n = pow(2, s.length());
    // for (int i = 0; i < n; i++)
    // {

    // }

    string s;
    cin >> s;

    int n = 1 << s.length();    // (1 << n) is same as pow(2,n);
    for (int i = 0; i < n; i++) // O(2^n)
    {
        string temp = "";
        for (int j = 0; j < s.length(); j++) // O(n);
        {
            if ((i & (1 << j)) != 0)
                temp.push_back(s[j]);
        }
        cout << temp << endl;
    }

    return 0;
}