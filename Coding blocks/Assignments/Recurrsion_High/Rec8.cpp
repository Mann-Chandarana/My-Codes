// Recursion - Dictionary order (smaller)

#include <bits/stdc++.h>
using namespace std;

void permutationsGreater(string &s, int start, string &temp, set<string> &st)
{
    if (start == s.length())
    {
        if (s < temp)
        {
            st.insert(s);
        }

        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        swap(s[i], s[start]);
        permutationsGreater(s, start + 1, temp, st);
        swap(s[i], s[start]);
    }
}

int main()
{
    string s;
    cin >> s;
    string temp = s;
    set<string> st;

    permutationsGreater(s, 0, temp, st);
    
    for (auto ele : st)
        cout << ele << endl;

    return 0;
}