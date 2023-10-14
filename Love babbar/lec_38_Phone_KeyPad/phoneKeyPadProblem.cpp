#include <bits/stdc++.h>
using namespace std;

void keyPad(string &digits, string &temp, int &start, string mapping[])
{
    if (start >= digits.length())
    {
        if (digits.length() > 0)
        {
            cout << temp << endl;
        }
        return;
    }

    int num = digits[start] - '0';
    string val = mapping[num];

    for (int i = 0; i < val.length(); i++)
    {
        temp.push_back(val[i]);
        keyPad(digits, temp, ++start, mapping);
        start--;
        temp.pop_back(); // Backtrack
    }
}

int main()
{
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string digits;
    cin >> digits;
    int start = 0;
    string temp;

    keyPad(digits, temp, start, mapping);

    return 0;
}