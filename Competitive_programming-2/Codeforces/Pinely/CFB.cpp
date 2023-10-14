/* https://codeforces.com/contest/1863/problem/B */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Solution :-
1) Here if the pos(x-1) > pos(x) then we have to do the action
  because for eg if vec - 2,1 is given
  then we have to do the operation to make vec - 1,2

2) In this solutin if we have already performed the operation for x-1 then we dont have to perform 
   operation for x 
*/

/* Solution - 1 */

void solve()
{
    ll n, res = 0;
    cin >> n;

    vector<ll> v(n + 1, 0), pos(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        pos[v[i]] = i;
    }

    for (ll i = 2; i <= n; i++)
    {
        if (pos[i - 1] > pos[i])
            res++;
    }
    cout << res << endl;
}

/* Solution -2 */

void solve()
{
    ll n;
    cin >> n;

    vector<ll> vec(n);

    for (auto &i : vec)
        cin >> i;

    vector<bool> visited(n + 1, false);

    ll answer = 0;
    for (auto &i : vec)
    {
        if (!visited[i - 1])
            answer++, visited[i] = true;

        else
            visited[i] = true;
    }
    answer--;
    cout << answer << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}