/////////// Slow solution

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll power(int n, int x)
{
    ll ans = 1;
    for (int i = 0; i < x; i++)
    {
        ans *= n;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int maxT, maxN, sumN;
        cin >> maxT >> maxN >> sumN;

        int cnt = 0;
        int ans = 0;

        while (sumN >= maxN && maxT != 0)
        {
            sumN -= maxN;
            ans += power(maxN, 2);
            cnt++;
            maxT--;
        }
        if (sumN != 0 && maxT > 0)
        {
            ans += pow(sumN, 2);
            maxT--;
        }
        cout << ans << endl;
    }

    return 0;
}