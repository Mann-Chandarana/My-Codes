#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int mn = min({a, b, c}), count = 0;

    bool pos = true;

    if (a % mn != 0 || b % mn != 0 || c % mn != 0)
        pos = false;

    while (a != mn)
    {
        if (count > 3)
        {
            pos = false;
            break;
        }
        count++, a -= mn;
    }
    while (b != mn)
    {
        if (count > 3)
        {
            pos = false;
            break;
        }
        count++, b -= mn;
    }
    while (c != mn)
    {
        if (count > 3)
        {
            pos = false;
            break;
        }
        count++, c -= mn;
    }

    if (count > 3)
        pos = false;

    if (pos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void solve()
{
    int *arr = new int[3];

    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    sort(arr, arr + 3);

    int operation = 0;

    if (arr[2] % arr[0] == 0 and arr[1] % arr[0] == 0)
    {
        operation += (arr[2] / arr[0] - 1);
        operation += (arr[1] / arr[0] - 1);
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
    if (operation <= 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
