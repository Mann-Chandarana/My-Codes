#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> vec(n);

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            sum += vec[i];
        }

        bool isOne = false;

        for (int i = 0; i < n; i++)
        {
            if (vec[i] == 1)
            {
                isOne = true;
                break;
            }
        }

        if (isOne || sum % 2)
        {
            cout << "CHEF" << endl;
        }
        else
        {
            cout << "CHEFINA" << endl;
        }
    }

    return 0;
}