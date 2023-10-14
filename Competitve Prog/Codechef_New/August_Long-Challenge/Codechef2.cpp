#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, y;
    cin >> t;

    while (t--)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        cin >> n >> x >> y;
        int dummy = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> dummy;
            pq.push(dummy);
        }

        int smaller_ele = 0;
        while (y > 0)
        {
            smaller_ele = pq.top();
            if ((smaller_ele ^ x) > smaller_ele)
            {
                pq.pop();
                pq.push(smaller_ele ^ x);
                y--;
            }
            else
            {
                break;
            }
        }
        if (y % 2)
        {
            smaller_ele = pq.top();
            pq.pop();
            pq.push(smaller_ele ^ x);
        }

        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    return 0;
}