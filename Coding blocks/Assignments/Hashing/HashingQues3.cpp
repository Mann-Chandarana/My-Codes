////////// Highest frequency

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, no;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        mp[no]++;
    }
    int maxi = INT_MIN;
    for (auto p : mp)
    {
        maxi = max(maxi, p.second);
    }

    for (auto p : mp)
    {
        if (p.second == maxi)
        {
            cout << p.first << endl;
        }
    }

    return 0;
}