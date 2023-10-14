/* https://www.codechef.com/START101C/problems/LPC */

#include <bits/stdc++.h>
using namespace std;

int Difference(char a, char b)
{
    int diff = abs(a - b);

    return min(diff, 10 - diff);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    string s, k;
    cin >> s >> k;

    if (s.find(k) != string::npos)
        cout << 0 << endl;
    else
    {
        int ans = INT_MAX;

        for (int i = 0; i <= (n - m); i++)
        {
            int diff = 0;

            for (int j = 0; j < m; j++)
                diff += Difference(s[i + j], k[j]);
            ans = min(ans, diff);
        }
        cout << ans << endl;
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