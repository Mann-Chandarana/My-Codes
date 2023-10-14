// Permutation GCD 

#include <iostream>
using namespace std;

int main()
{
    int t, x, n;
    cin >> t;

    while (t--)
    {
        cin >> n >> x;
        if (x < n)
        {
            cout << -1 << endl;
        }
        else
        {
            int diff_bet = x - n + 1;
            cout << diff_bet << " ";

            for (int i = 1; i <= n; i++)
            {
                if (i != diff_bet)
                {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}