#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int problem = 0;

        while (n > 0)
        {
            if (n >= 100)
            {
                problem++;
                n -= 100;
                continue;
            }
            problem++;
            n--;
        }

        if (problem > 10)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << problem << endl;
        }
    }

    return 0;
}