/* Transfusion Chain */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, A = 0, B = 0, AB = 0, O = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string querey;
            cin >> query;
            if (query == "A")
                A++;
            else if (query == "B")
                B++;
            else if (query == "AB")
                AB++;
            else if (query == "O")
                O++;
        }

        long long count = 0;

        if (O != 0)
            count += O;

        count = count + max(A, B) + AB;

        cout << count << endl;
    }

    return 0;
}