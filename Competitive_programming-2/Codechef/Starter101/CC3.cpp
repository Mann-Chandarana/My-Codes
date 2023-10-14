/* https://www.codechef.com/START101C/problems/WARRIORCHEF */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/* Approach -1)  */

void solve()
{
    int N, H;
    cin >> N >> H;

    vector<int> enemies(N);

    for (auto &i : enemies)
        cin >> i;

    int ans = 0, low = 0, high = 1e9;

    auto check = [&](int x)
    {
        int tmp = H;

        for (auto e : enemies)
        {
            if (e <= x)
                continue;
            tmp -= e;
            if (tmp <= 0)
                return 0;
        }
        return 1;
    };

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(mid))
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans << endl;
}

/* Appraoch -2)  */

void solve()
{
    int N, H;
    cin >> N >> H;

    vector<int> enemies(N);

    for (auto &i : enemies)
        cin >> i;

    sort(all(enemies), greater<int>());

    int resistance = 0;

    for (int i = 0; i < N; i++)
    {
        if (H - enemies[i] > 0)
            H -= enemies[i];
        else
        {
            resistance = enemies[i];
            break;
        }
    }
    cout << resistance << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}