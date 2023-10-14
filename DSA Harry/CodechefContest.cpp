#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, k, f;
        cin >> n >> k >> f;
        vector<pair<int, int>> inv(n);
        for (int i = 0; i < n; i++)
        {
            cin >> inv[i].first >> inv[i].second;
        }

        sort(inv.begin(), inv.end());

        int ans = 0;
        int max_end = inv[0].second;

        for (int i = 1; i < n; i++)
        {
            ans += max(0, inv[i].first - max_end);
            max_end = max(max_end, inv[i].second);
        }

        ans += inv[0].first;
        ans += f - max_end;

        cout << (ans >= k ? "YES" : "NO") << endl;
    }

    return 0;
}
