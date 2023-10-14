/* ALT-Tab */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    vector<string> query(n);

    for (int i = 0; i < n; i++)
    {
        string val;
        cin >> val;
        query[i] = val;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        string possible_answer = query[i];
        if (mp.find(possible_answer) != mp.end())
            continue;
        else
        {
            int len = possible_answer.length();
            cout << possible_answer[len - 2] << possible_answer[len - 1];
            mp[possible_answer]++;
        }
    }

    return 0;
}