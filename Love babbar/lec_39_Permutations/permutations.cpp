#include <bits/stdc++.h>
using namespace std;

void permutations(vector<string> &ans, string &s, int start)
{
    if (start >= s.length())
    {
        ans.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        swap(s[start], s[i]);
        permutations(ans, s, start+1);

        // backtrack
        swap(s[start], s[i]);
        // Because we are passing string s by reference, we need go get back our original string.
    }
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans;

    cout << endl
         << endl;
    permutations(ans, s, 0);

    for (auto ele : ans)
        cout << ele << endl;

    cout << endl
         << "string after permutations: " << s << endl;

    return 0;
} // Que-46 in leetcode
