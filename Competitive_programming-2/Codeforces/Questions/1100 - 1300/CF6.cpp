/* https://codeforces.com/problemset/problem/1839/C */

/* C. Insert Zero and Invert Prefix  :- 1300 */

/*
Solutions :-
1) Here first iterate the i upto the index which where vec[i+1] == 0 and vec[i] == 1
2) Then store the count of zeros and ones 
3) Then (print 0) for (zeros-1) times
4) Then (print 1) for (ones) time 
5) Then print the total number of ones
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

void solve()
{
    int n;
    cin >> n;

    vi vec(n);
    for (auto &i : vec)
        cin >> i;

    if (vec[n - 1] == 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;

        reverse(all(vec));
        int i = 0;

        while (i < n)
        {
            int one = 0, zero = 0;

            while (i < n and vec[i] == 0)
                zero++,i++;

            while (i < n and vec[i] == 1)
                one++,i++;

            int dummy = one;
            while ((zero--) > 1)
                cout << 0 << " ";
            while ((one--) > 0)
                cout << 0 << " ";
            cout << dummy << " ";
        }
        cout << endl;
    }
}

int main()
{
    fastread();
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}