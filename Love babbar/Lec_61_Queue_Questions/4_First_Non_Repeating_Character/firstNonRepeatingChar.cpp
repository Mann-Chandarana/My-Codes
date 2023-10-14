#include <bits/stdc++.h>
using namespace std;

string nonRepeat(string &s)
{
    unordered_map<char, int> mp;
    string ans = "";
    queue<int> q;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        q.push(s[i]);

        while (!q.empty())
        {
            if (mp[q.front()] > 1)
                q.pop();
            else
            {
                ans += q.front();
                break;
            }
        }
        if (q.empty())
            ans += '#';
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << nonRepeat(s) << endl;

    return 0;
}