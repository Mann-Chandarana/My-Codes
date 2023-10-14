#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int x;
    cin >> x;
    int ans = 0;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        ans += (x / v[i]);
        x -= (x / v[i]) * v[i];
    }
    cout << ans << endl;

    return 0;
}