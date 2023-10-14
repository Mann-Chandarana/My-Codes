/* https://codeforces.com/contest/1861 */

/*
Solution :-
1) First of all we have to find the prime number from 1 to 9 that is 
  1,3,5,7

  now select any two prime numbers and form the word from it 
  and if for example selecting two prime number 3 and 7
  1) First number will be 37
  2) Second number will be 73
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;

    int pos1, pos2;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '3')
            pos1 = i;

        if (s[i] == '7')
            pos2 = i;
    }

    if (pos1 < pos2)
    {
        cout << 37 << endl;
        return;
    }
    else
    {
        cout << 73 << endl;
        return;
    }
    cout << -1 << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}