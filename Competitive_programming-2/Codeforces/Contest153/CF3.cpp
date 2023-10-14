/* https://codeforces.com/contest/1860/problem/C */

/* 
Solution :-
a) Here basically we have to find the element which has only one element smaller before it
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int first_min = vec[0], second_min = INT_MAX, ans = 0;

    for (int i = 1; i < n; i++)
    {
        first_min = min(vec[i], first_min);

        if (second_min > vec[i] and vec[i] > first_min)
        {
            ans++;
            second_min = vec[i];
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}