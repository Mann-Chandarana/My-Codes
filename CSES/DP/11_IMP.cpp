#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

/** Tabulation **/

void solve(int n, int max_sum,vi &nums)
{
    vector<int> dp(max_sum + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int sum = max_sum; sum >= nums[i]; sum--)
        {
            if (dp[sum - nums[i]])
                dp[sum] = 1;
        }
    }

    vi answer;

    for (int i = 1; i <= max_sum; i++)
    {
        if (dp[i])
            answer.pb(i);
    }

    cout << answer.size() << endl;

    for (auto element : answer)
        cout << element << " ";
    cout << endl;
}

int main()
{
    fastread();

    int n;
    cin >> n;

    vi nums(n);

    for (auto &i : nums)
        cin >> i;

    int max_sum = accumulate(all(nums), 0);

    solve(n,max_sum,nums);

    return 0;
}