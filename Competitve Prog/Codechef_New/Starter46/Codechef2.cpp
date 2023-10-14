#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> vec(n);
        unordered_map<int, int> mp;

        int attack = 0, defense = 0;

        ll ans;

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            mp[vec[i]]++;
        }
        bool isAllgreater = false;
        bool isAllSmaller = false;
        bool isEqual = mp.size() == 1 ? true : false;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] > 500)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        isAllgreater = cnt1 == n ? true : false;
        isAllSmaller = cnt2 == n ? true : false;

        if (isEqual)
        {
            for (int i = 0; i < n - 1; i++)
            {
                attack += vec[i];
            }
            defense = vec[n - 1];
            ans = attack * defense;
        }
        else if (isAllSmaller)
        {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                maxi = max(maxi, vec[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (vec[i] == maxi)
                {
                    continue;
                }
                attack += vec[i];
                ans = attack * (1000 - maxi);
            }
        }
        else if (isAllgreater)
        {
            int mini = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                mini = min(mini, vec[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (vec[i] == mini)
                {
                    continue;
                }
                attack += vec[i];
                ans = attack * (1000 - mini);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (vec[i] >= 500)
                {
                    attack += vec[i];
                }
                else
                {
                    defense += (1000 - vec[i]);
                }
            }
            ans = attack * defense;
        }
        cout << ans << endl;
    }

    return 0;
}