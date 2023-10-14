/* Candies :- NDONE */

/* https://codeforces.com/problemset/problem/1810/B */

/*
First, we notice that after each operation, the number of candies is always a odd number. So even numbers can not be achieved.

Then consider how the binary representation changes for a odd number x
, after turn it into 2x+1
 or 2x−1
.

For the 2x+1
 operation: …1¯¯¯¯¯¯¯¯¯
 turns into …11¯¯¯¯¯¯¯¯¯¯¯¯
.

For the 2x−1
 operation: …1¯¯¯¯¯¯¯¯¯
 turns into …01¯¯¯¯¯¯¯¯¯¯¯¯
.

So, the operation is just insert a 0/1
 before the last digit. And the answer for an odd n
 is just the binary representation of n
, after removing the last digit.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;

    if (!(n & 1))
    {
        cout << -1 << endl;
        return;
    }

    vi ans;
    int f = 0;
    for (int i = 29; i >= 1; i--)
    {
        if ((n >> i) & 1)
            f = 1, ans.pb(2);
        else if (f)
            ans.pb(1);
    }

    cout << ans.size() << endl;

    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}