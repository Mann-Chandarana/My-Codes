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

int mod = 1e9 + 7;

int main()
{
    fastread();
    int n;
    cin >> n;

    int answer = 1;

    for (int i = 0; i < n; i++)
    {
        answer *= 2;
        answer %= mod;
    }
    cout << answer << endl;

    return 0;
}