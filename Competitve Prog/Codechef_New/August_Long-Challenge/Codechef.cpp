/////////////// Two trains

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        vector<int> post(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> v[i];
            if (i - 1 < 0)
            {
                post[i] = v[i];
                continue;
            }
            post[i] = post[i - 1] + v[i];
        }

        a = 0;
        b = v[0];
        for (int i = 0; a != post[n - 2]; i++)
        {
            a += v[i];
            b += v[i];
            if (i + 1 < (n - 1) && b < post[i + 1])
            {
                b += post[i + 1] - b;
            }
        }
        cout << b << endl;
    }

    return 0;
}