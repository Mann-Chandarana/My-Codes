/////////// Average permutation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        list<int> l;
        int n;
        cin >> n;
        if (n <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            cout << n - 1 << " " << n - 2 << " ";
            for (int i = 1; i < n - 3; i++)
            {
                cout << i << " ";
            }
            cout << n - 3 << " " << n;
        }
        cout << "\n";
    }

    return 0;
}