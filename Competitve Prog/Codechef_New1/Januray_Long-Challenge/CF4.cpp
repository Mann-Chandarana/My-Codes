#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        int b[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                swap(a[i], b[i]);
            }
        }

        vector<vector<int>> combined(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            combined[i][0] = a[i];
            combined[i][1] = b[i];
        }

        sort(combined.begin(), combined.end());

        int firstMin[n], firstMax[n], lastMin[n], lastMax[n];

        firstMax[0] = combined[0][0];
        firstMin[0] = combined[0][0];
        lastMax[n - 1] = combined[n - 1][1];
        lastMin[n - 1] = combined[n - 1][1];

        for (int i = 1; i < n; i++)
        {
            firstMin[i] = min(firstMin[i - 1], combined[i][0]);
            firstMax[i] = max(firstMax[i - 1], combined[i][0]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            lastMin[i] = min(lastMin[i + 1], combined[i][1]);
            lastMax[i] = max(lastMax[i + 1], combined[i][1]);
        }

        int maximum = combined[n - 1][0];
        int minimum = combined[0][0];
        int ans = maximum - minimum;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                maximum = lastMax[0];
                minimum = lastMin[0];
            }
            else
            {
                maximum = max(firstMax[i - 1], lastMax[i]);
                minimum = min(firstMin[i - 1], lastMin[i]);
            }
            ans = min(ans, maximum - minimum);
        }
        cout << ans << endl;
    }

    return 0;
}