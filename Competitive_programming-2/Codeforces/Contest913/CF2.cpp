/* B. YetnotherrokenKeoard */

/* https://codeforces.com/contest/1907/problem/B */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    string str;
    cin >> str;

    int lower = 0, upper = 0;

    string answer;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'B')
            upper++;
        else if (str[i] == 'b')
            lower++;

        else if (islower(str[i]))
        {
            if (lower == 0)
                answer.pb(str[i]);
            else
                lower--;
        }
        else
        {
            if (upper == 0)
                answer.pb(str[i]);
            else
                upper--;
        }
    }
    reverse(all(answer));

    cout << answer << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}