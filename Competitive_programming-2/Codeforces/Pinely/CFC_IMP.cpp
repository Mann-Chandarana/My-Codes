// Question Type :- observation

/* https://codeforces.com/contest/1863/problem/C */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/*
Solution :-

Question :- 5 5
            1 2 3 4 5

Answer :-
--> 1st iteration
    0 1 2 3 4
--> 2nd iteration
    5 0 1 2 3
--> Third iteration
    4 5 0 1 2
--> fourth iteration
    3 4 5 0 1
--> fifth iteration
    2 3 4 5 0

Approach push remainig number :- 1 2 3 4 5 0
(k % n+1) = 5 and n+1 - 5 = 1

will give you the index
*/

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> vec(n);

    for (auto &i : vec)
        cin >> i;

    ll sum = (n * (n + 1)) / 2;

    ll arr_sum = accumulate(all(vec), 0);

    ll missing_no = abs(sum - arr_sum);
    vec.push_back(missing_no);

    int rem = k % (n + 1);
    int idx = (n + 1 - rem) % (n + 1);
    vector<int> ans;

    for (int i = idx; i < n + 1; i++)
        ans.push_back(vec[i]);

    for (int i = 0; i < idx - 1; i++)
        ans.push_back(vec[i]);

    if (ans.size() > n)
        ans.pop_back();

    for (auto i : ans)
        cout << i << " ";

    cout << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}