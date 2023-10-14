#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int n, sp, ep;
    cin >> n;
    int center[n], radius[n];
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> center[i] >> radius[i];
        sp = center[i] - radius[i];
        ep = center[i] + radius[i];
        v.push_back({sp, ep});
    }
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    int fin = v[0].first;

    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= fin)
        {
            ans++;
            fin = v[i].second;
        }
    }
    cout << n - ans << endl;

    return 0;
}