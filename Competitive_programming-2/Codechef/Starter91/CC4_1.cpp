/* Maximum Sum Permutation */

// https://www.codechef.com/problems/MAXSUMPERM?tab=statement

#include <bits/stdc++.h>
using namespace std;

/*
Most import concept of storing the index in range in frequency array using prefix sum
1 4
2 3

start = 1 and end+1 = -1

Indexes :- 0 1 2  3  4
           1 1 0 -1 -1
Prefix :-  1 2 2 1 0
sum
 */

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n = 0, q = 0;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<pair<int, int>> mat(q);
        vector<pair<int, int>> countInQuery(n);

        for (int i = 0; i < n; i++)
        {
            countInQuery[i] = make_pair(0, i);
        }

        for (int i = 0; i < q; i++)
        {
            int l = 0, r = 0;
            cin >> l >> r;
            mat[i] = make_pair(l, r);
            countInQuery[l - 1].first += 1;
            if (r < n)
                countInQuery[r].first -= 1;
        }
        for (int i = 1; i < n; i++)
        {
            countInQuery[i].first += countInQuery[i - 1].first;
        }

        sort(countInQuery.begin(), countInQuery.end());

        int x = 0;
        vector<int> temp(n, 0);
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--)
        {
            temp[countInQuery[i].second] = v[i];
            x += v[i] * countInQuery[i].first;
        }
        cout << x << endl;
        for (int i = 0; i < n; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}