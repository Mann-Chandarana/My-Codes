#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            mp[vec[i]]++;
        }

        vector<pair<int, int>> vec1;

        for (auto ele : mp)
        {
            vec1.push_back(ele);
        }

        sort(vec1.begin(), vec1.end(), compare);
        int ans = 0;

        vec1.erase(vec1.begin());

        for (auto ele : vec1)
        {
            ans += ele.second;
        }
        cout << ans << endl;
    }

    return 0;
}