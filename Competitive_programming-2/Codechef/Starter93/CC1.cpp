/* 7 Rings */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, X;
        cin >> N >> X;

        string value = to_string(N * X);

        if (value.size() == 5 and value[0] != '0')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}