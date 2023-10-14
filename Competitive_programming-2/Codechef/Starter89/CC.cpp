/******************* Parliament *******************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N, X;
    cin >> t;

    while (t--)
    {
        cin >> N >> X;
        if (X == 0 || X * 2 < N)
            cout << "NO" << endl;

        else
            cout << "YES" << endl;
    }

    return 0;
}