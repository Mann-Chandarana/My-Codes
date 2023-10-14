#include "bits/stdc++.h"
using namespace std;

#define pii pair<int, int>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define vi vector<int>

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> a(k);

    rep(i, 0, k)
    {
        int size;
        cin >> size;
        a[i] = vector<int>(size);

        rep(j, 0, size)
        {
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    rep(i, 0, k)
    {
        pq.push({a[i][0], i});
    }

    vi ans;

    while (!pq.empty())
    {
        pii tempPair = pq.top();
        pq.pop();

        ans.push_back(tempPair.first);

        if (idx[tempPair.second] + 1 < a[tempPair.second].size())
        {
            pq.push({a[tempPair.second][idx[tempPair.second] + 1], tempPair.second});
        }
        idx[tempPair.second]++;
    }

    rep(i, 0, ans.size())
            cout
        << ans[i] << " ";
    cout << endl;

    return 0;
}