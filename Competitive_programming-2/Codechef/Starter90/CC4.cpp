/* AP free sequences */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        vector<int> vec(N);

        for (int i = 0; i < N; i++)
            cin >> vec[i];

        bool free = true;
        for (int i = 0; i < N - 2; i++)
        {
            for (int k = i + 1; k < N - 1; k++)
            {
                for (int z = k + 1; z < N; z++)
                {
                    if (vec[k] - vec[i] == vec[z] - vec[k])
                        free = false;
                }
            }
        }

        if (!free)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}