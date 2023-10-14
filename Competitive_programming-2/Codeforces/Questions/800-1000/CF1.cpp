/* NDONE */

/* https://codeforces.com/problemset/problem/1873/D */

/*
Very Easy solution 
Here we have to add k-1 if Black is found so that which ever black comes in between gets ignore
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, K, i = 0;
    cin >> N >> K;

    string s;
    cin >> s;

    int answer = 0;

    while (i < N)
    {
        if (s[i] == 'B')
            answer++, i += (K - 1);

        i++;
    }
    cout << answer << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}