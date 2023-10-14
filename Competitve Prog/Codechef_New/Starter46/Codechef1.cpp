#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    int t, n, ele;
    cin >> t;

    while (t--)
    {
        cin >> n;
        unordered_map<int, int> mp;
        string ans = "YES";

        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            mp[ele]++;
        }

        for (auto people : mp)
        {
            if (people.second % people.first != 0)
            {
                ans = "NO";
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}