#include <iostream>
#include <algorithm>
using namespace std;
///////////////////////////////////////////
int main()
{
    int t, X, Y;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> X >> Y;

        while (!(__gcd(X, Y) > 1))
        {
            if ((X % 2 != 0) || (Y % 2 != 0))
            {

                if ((__gcd(X, Y + 1) > 1))
                {
                    Y = Y + 1;
                    n++;
                    continue;
                }
                else if ((__gcd(X + 1, Y)))
                {
                    X = X + 1;
                    n++;
                    continue;
                }
            }
        }
        cout << n << endl;
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        int n;
        if (A % 2 == 0 && B % 2 == 0)
        {
            n = 0;
        }
        else if (__gcd(A, B) != 1)
        {
            n = 0;
        }
        else if (__gcd(A + 1, B) > 1 || __gcd(A, B + 1) > 1)
        {
            n = 1;
        }
        else
        {
            n = 2;
        }
        cout << n << endl;
    }

    return 0;
// }