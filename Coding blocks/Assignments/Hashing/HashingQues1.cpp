// Intersection of two arrays

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, no;
    cin >> n;
    vector<int> vec1, ans;
    unordered_map<int, int> mp1;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        vec1.push_back(no);
    }

    for (auto ele : vec1)
    {
        mp1[ele]++;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        if (mp1[no] > 0)
        {
            ans.push_back(no);
            mp1[no]--;
        }
    }
    sort(ans.begin(), ans.end());
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
        {
            cout << ans[i];
            break;
        }
        cout << ans[i] << ", ";
    }

    cout << "]" << endl;

    return 0;
}