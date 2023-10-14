/* Chat room :- 1000 */

/* https://codeforces.com/problemset/problem/58/A */

#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    string s;
    cin >> s;

    string to_find = "hello";
    int i = 0, j = 0;

    while (i < s.length())
    {
        if (j == to_find.size())
            break;

        if (s[i] == to_find[j])
            j++;
        i++;
    }
    if (j == to_find.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    fastread();
    solve();

    return 0;
}