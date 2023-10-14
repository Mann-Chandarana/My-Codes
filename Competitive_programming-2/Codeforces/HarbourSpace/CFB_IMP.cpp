/* https://codeforces.com/contest/1864/problem/B */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/*
Solution :-

// Observation

1) Every odd index can be swapped with each other
2) Every even index can be swapped with each other

--> By observing the testcases

1) if k is even the simple sort the string
2) if k is odd then sort the odd index character and then sort the even index character
   then add it to the final answer
*/

void solve()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (!(k & 1)) // if k is even
    {
        sort(all(s));
        cout << s << endl;
    }

    else // if k is odd
    {
        string odd = "", even = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (!(i & 1))
                even += s[i];

            else
                odd += s[i];
        }

        sort(all(odd));
        sort(all(even));

        ll o = 0, e = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (!(i & 1))
                s[i] = even[e++];

            else
                s[i] = odd[o++];
        }
        cout << s << endl;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}