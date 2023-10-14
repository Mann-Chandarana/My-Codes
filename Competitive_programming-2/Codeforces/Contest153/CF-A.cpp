/* https://codeforces.com/contest/1860/problem/A */

/*
Solution:-

1) If the string contains two same closing or opening bracket like "(()" or "()))"
   then the answer will be "()()()"

2) If the string contains opposite bracket string then the answer will be "((()))"

This both are the only possiblity of the given question
*/

#include <bits/stdc++.h>
using namespace std;

/* Solution -1) */

void solve()
{
    string s;
    cin >> s;

    if (s == "()")
        cout << "NO" << endl;

    else
    {
        cout << "YES" << endl;

        ////////////// Creating answer -1)

        string answer1(s.length(), '(');
        answer1 += string(s.length(), ')');

        ////////////// Creating answer -2)

        string answer2 = "";

        for (int i = 0; i < s.length(); i++)
            answer2 += "()";

        if (answer1.find(s) != string::npos)
            cout << answer2 << endl;
        else
            cout << answer1 << endl;
    }
}

/* Solution -2) */

void solve()
{
    string s;
    cin >> s;

    if (s == "()")
        cout << "NO" << endl;

    else
    {
        cout << "YES" << endl;

        string answer1 = "", answer2 = "";

        int n = s.length();

        for (int i = 0; i < (2 * n); i++)
        {
            answer1 += "()"[i & 1];
            answer2 += ")("[i < n];
        }

        if (answer1.find(s) != string::npos)
            cout << answer2 << endl;
        else
            cout << answer1 << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}