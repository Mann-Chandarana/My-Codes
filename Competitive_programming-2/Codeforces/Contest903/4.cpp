/* https://codeforces.com/contest/1881/problem/D */

/* D. Divide and Equalize */

/* Here if we can distribute the divisors of all the number equally then we can form the answer
  1) So here we create the map of the divisor and its count
    and if the count is divisible by n then only we will get out answer
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> vec(n);

        for (auto &i : vec)
            cin >> i;

        unordered_map<ll, ll> mp;

        for (ll i = 0; i < n; i++)
        {
            int num = vec[i];

            for (ll i = 2; i <= sqrt(num); i++)
            {
                while (num % i == 0)
                {
                    mp[i]++;
                    num /= i;
                }
            }
            if (num > 1)
                mp[num]++;
        }

        bool answer = true;
        for (auto element : mp)
        {
            if (element.second % n != 0)
            {
                answer = false;
                break;
            }
        }
        if (answer)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}