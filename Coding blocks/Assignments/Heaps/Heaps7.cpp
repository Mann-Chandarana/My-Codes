///////////// Hostel visit

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n, k, option, x, y;
    cin >> n >> k;
    priority_queue<ll> maxHeap;

    while (n--)
    {
        cin >> option;
        if (option == 1)
        {
            cin >> x >> y;
            maxHeap.push(pow(x, 2) + pow(y, 2));
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        else if (option == 2)
        {
            cout << maxHeap.top() << endl;
        }
    }

    return 0;
}