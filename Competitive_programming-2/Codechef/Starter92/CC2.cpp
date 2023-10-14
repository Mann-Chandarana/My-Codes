/* Water Filling */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int B1, B2, B3;
        cin >> B1 >> B2 >> B3;

        int answer = B1 + B2 + B3;
        if (answer > 1)
            cout << "Not now" << endl;
        else
            cout << "Water filling time" << endl;
    }

    return 0;
}