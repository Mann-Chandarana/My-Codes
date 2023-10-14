///////////// Hello Equation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x;
    cin >> t;

    while (t--)
    {
        cin >> x;
        double a, b = 1;
        int temp;
        bool hello_equa = false;
        while (b*b < x)
        {
            a = ((x - (2 * b)) / (2 + b));
            temp = a;
            if (a > 0 && ((a - temp) <= 0))
            {
                // cout << a << " " << endl;
                hello_equa = true;
                break;
            }
            b++;
        }
        // cout << a << " " << b << endl;
        if (hello_equa)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}