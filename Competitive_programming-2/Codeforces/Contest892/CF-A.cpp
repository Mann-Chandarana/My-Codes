/* https://codeforces.com/contest/1859/problem/A */

/*
Approach :- Here maximum element will not divide any element,
so we keep the maximum element in array c and remaining element in array B
*/

#include <bits/stdc++.h>
using namespace std;

/* Upsolve solution */

void solve()
{
    int n = 0;
    cin >> n;
    vector<int> inp;
    inp.assign(n, 0);
    for (auto &x : inp)
        cin >> x;
    sort(inp.begin(), inp.end());
    if (inp.back() == inp[0])
    {
        cout << "-1\n";
        return;
    }
    else
    {
        int it = 0;
        while (inp[it] == inp[0])
            it++;
        cout << it << " " << n - it << "\n";
        for (int j = 0; j < it; ++j)
            cout << inp[j] << " ";
        cout<<endl;
        for (int j = it; j < n; ++j)
            cout << inp[j] << " ";
    }
}

/* Solution -1 */

void f()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> b, c;

    int maxi = *max_element(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == maxi)
            c.push_back(maxi);
        else
            b.push_back(vec[i]);
    }

    if (c.size() == 0 || b.size() == 0)
        cout << -1 << endl;
    else
    {
        cout << b.size() << " " << c.size() << endl;

        for (auto element : b)
            cout << element << " ";

        cout << "\n";

        for (auto element : c)
            cout << element << " ";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}