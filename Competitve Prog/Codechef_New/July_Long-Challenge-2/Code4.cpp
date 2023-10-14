///////// Maximize Difference

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N, M;
    cin >> t;

    while (t--)
    {
        cin >> N >> M;
        int len_max = INT_MIN;
        int num1 = 0, num2 = 0;
        int i = N;
        while (i <= M and i<=2*N)
        {
            int nearest_multiple = M;

            if (nearest_multiple % i != 0)
            {
                nearest_multiple = nearest_multiple - (nearest_multiple % i);
                // cout << nearest_multiple << endl;
            }
            // cout << "Nearet multiple " << nearest_multiple << " N " << N << endl;
            // cout << "Length is " << nearest_multiple - N << endl;
            if (nearest_multiple - i >= len_max)
            {
                len_max = nearest_multiple - i;
                // cout << "Hello" << endl;
                num1 = i;
                num2 = nearest_multiple;
            }

            i++;
        }
        cout << num1 << " " << num2 << endl;
    }

    return 0;
}