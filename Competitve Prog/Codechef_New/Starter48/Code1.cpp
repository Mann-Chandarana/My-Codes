/////////// Fill the grids

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N, M;
    cin >> t;

    while (t--)
    {
        cin >> N >> M;
        int ans = 0;
        if (N % 2 == 0 and M % 2 != 0)
        {
            ans = N;
        }
        else if (M % 2 == 0 and N % 2 != 0)
        {
            ans = M;
        }
        else if (M % 2 != 0 and N % 2 != 0)
        {
            ans = N + (M - 1);
        }
        else
        {
            ans = 0;
        }
        cout << ans << endl;
    }

    return 0;
}