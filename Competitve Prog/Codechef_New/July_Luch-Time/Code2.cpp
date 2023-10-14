////// Largest family

#include <bits/stdc++.h>

using namespace std;

typedef long ll;

void solve()
{
    ll n;
    cin >> n;

    std::vector<ll> A(n, 0);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    ll run = 0, cnt = 0;

    for (ll a : A)
    {
        run += a;
        if (run < n)
        {
            // cout << run << " ";
            cnt++;
        }
        else
            break;
    }

    cout << cnt << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    size_t t;
    cin >> t;

    while (t)
    {

        solve();

        t--;
    }
    return 0;
}
