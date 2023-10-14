/* https://codeforces.com/problemset/problem/337/A */

/* A. Puzzles :- 900 */

#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    int n, m;
    cin >> n >> m;

    vi vec(m);
    for (auto &i : vec)
        cin >> i;

    sort(all(vec));

    int i = 0, j = n - 1, mini = INT_MAX;

    while (j < m)
    {
        mini = min(mini, vec[j] - vec[i]);
        i++, j++;
    }
    cout << mini << endl;

    return 0;
}