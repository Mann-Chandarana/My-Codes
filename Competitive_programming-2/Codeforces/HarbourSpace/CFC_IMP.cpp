/* https://codeforces.com/contest/1864/problem/C */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()

/*
Solution :-

*** Observation
------> Here the last most set bit will be the divisor

*** Solution

1) We will subtract the number with the 2^(lastMostSetBit) until only last set bit is remaining
2) then we will divide it by two
*/

void solve()
{
    int n;
    cin >> n;

    vector<int> answer;

    int set_bit = 0, temp = n;

    while (temp > 0)
    {
        temp = (temp & temp - 1);
        set_bit++;
    }

    answer.push_back(n);

    for (int i = 0; i < set_bit - 1; i++)
    {
        int last_set = n & -n;
        n = n - last_set;
        answer.push_back(n);
    }

    while (n > 1)
    {
        n /= 2;
        answer.push_back(n);
    }

    cout << sz(answer) << endl;
    for (auto element : answer)
        cout << element << " ";

    cout << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}