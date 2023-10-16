/* ND :- D. Strong Vertices :- 1300 */

/* https://codeforces.com/problemset/problem/1857/D */

/*
Approach :-
    au-av >= bu-bv
    au-bu >= av-bv

so therefore find the maximum difference from the given two arrays and then count the occurence of the maximum difference
and print it

because no difference can be greater than the maximum difference.
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vi a(n), b(n);

        for (auto &i : a)
            cin >> i;

        for (auto &i : b)
            cin >> i;

        int mx = INT_MIN;

        for (int i = 0; i < n; i++)
            mx = max(mx, a[i] - b[i]);

        int c = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] == mx)
                c++;
        }

        cout << c << endl;

        for (int i = 0; i < n; i++)
        {
            if (a[i] - b[i] == mx)
                cout << i + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}