#include <bits/stdc++.h>
using namespace std;

int _ceil(int max, int y)
{
    if (max % y == 0)
    {
        return max / y;
    }
    else
    {
        return (max / y) + 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        int a[n];
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
            {
                max = a[i];
            }
        }

        if (y > x)
        {
            cout << _ceil(max, y) << "\n";
        }
        else
        {
            int blimps = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                a[i] -= blimps * y;
                if (a[i] > 0)
                {
                    blimps += _ceil(a[i], x);
                }
            }
            cout << blimps << "\n";
        }
    }
    return 0;
}