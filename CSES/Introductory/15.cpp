#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long int
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

//////// Approach -1)

ll solve(int index, ll sum1, ll sum2, int n, vi &vec)
{
    if (index == n)
        return abs(sum1 - sum2);

    return min(solve(index + 1, sum1 + vec[index], sum2, n, vec), solve(index + 1, sum1, sum2 + vec[index], n, vec));
}

//////// Approach -2)

int solve(vi &vec)
{
    int n = vec.size();

    ll total = accumulate(all(vec), 0), ans = INT_MAX;

    for (lli i = 0; i < 1 << n; i++)
    {
        lli s = 0;
        for (lli j = 0; j < n; j++)
        {
            if (i & 1 << j)
                s += arr[j];
        }
        lli curr = abs((total - s) - s);
        ans = min(ans, curr);
    }
    return ans;
}

int main()
{
    fastread();
    int n;
    cin >> n;

    vi vec(n);
    for (auto &i : vec)
        cin >> i;

    cout << solve(vec) << endl;

    return 0;
}