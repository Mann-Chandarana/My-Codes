// https://codeforces.com/problemset/problem/208/A

/* A. Dubstep :- 900 */

#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    string s;
    cin >> s;
    bool flag = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'W' and s[i + 1] == 'U' and s[i + 2] == 'B')
        {
            i += 2;
            if (flag)
                cout << " ";
        }
        else
        {
            flag = true;
            cout << s[i];
        }
    }

    return 0;
}