/* Make money*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, X, C;
        cin >> N >> X >> C;

        int sum = 0;
        vector<int> bags(N);

        for (int i = 0; i < N; i++)
        {
            cin >> bags[i];
            sum += bags[i];
        }
        sort(bags.begin(), bags.end());
        int sum1 = sum;
        for (int i = 0; i < N; i++)
        {
            sum1 += (X - bags[i] - C);
            if (sum1 > sum)
            {
                sum = sum1;
            }
            else
            {
                break;
            }
        }
        cout << sum << endl;
    }

    return 0;
}