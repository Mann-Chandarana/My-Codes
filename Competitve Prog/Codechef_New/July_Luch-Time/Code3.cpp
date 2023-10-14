//// Maximum Median matching
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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);

        int start = (n - 1) / 2;
        int end = n - 1;
        int ans = 0;
        for (int i = start; i < n; i++)
        {
            ans = min(ans, a[i] + b[end]);
            end--;
        }
        cout << ans << endl;
    }

    return 0;
}