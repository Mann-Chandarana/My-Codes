/* Watermelon */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (!(n & 1) and n>2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}