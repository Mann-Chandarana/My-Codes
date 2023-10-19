/* https://codeforces.com/contest/1881/problem/A */

/* A. Don't Try to Count */

#include <iostream>
using namespace std;
#define ll long long

/* Approach -1) Fixing boundary using the length of the string given in the question  */

void solve()
{
    ll n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int count = 0;

    for (int i = 0; i < 6; i++)
    {
        if (a.find(b) != string::npos)
        {
            cout << count << endl;
            return;
        }
        count++;
        a += a;
    }
    cout << -1 << endl;
}

/* Approach -1) Fixing boundary using logical concept */

void solve()
{
    ll n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int count = 0;

    while (true)
    {
        if (a.find(b) != string::npos)
        {
            cout << count << endl;
            return;
        }
        if (count != 0 and a.length() > (2 * b.length()))
        {
            count = -1;
            break;
        }
        count++;
        a += a;
    }

    cout << count << endl;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}
