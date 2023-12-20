/* B. Vika and the Bridge */

/* https://codeforces.com/problemset/problem/1848/B */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

void solve()
{
    int n, k;
    cin >> n >> k;

    vi nums(n);

    for (auto &i : nums)
        cin >> i;

    vi last(k + 1, -1);
    vi max_step(k + 1), max_step2(k + 1);

    for (int i = 0; i < n; ++i)
    {
        int step = i - last[nums[i]];

        if (step > max_step[nums[i]])
        {
            max_step2[nums[i]] = max_step[nums[i]];
            max_step[nums[i]] = step;
        }
        else
            max_step2[nums[i]] = max(step, max_step2[nums[i]]);

        last[nums[i]] = i;
    }

    for (int i = 1; i <= k; i++)
    {
        int step = n - last[i];

        if (step > max_step[i])
            max_step2[i] = max_step[i], max_step[i] = step;
        else
            max_step2[i] = max(step, max_step2[i]);
    }

    int answer = INT_MAX;

    for (int i = 1; i <= k; i++)
        answer = min(answer, max(((max_step[i] + 1) / 2), max_step2[i]));

    cout << answer - 1 << endl;
}

int main()
{
    fastread();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}