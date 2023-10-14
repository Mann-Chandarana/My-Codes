/* RSA algorithm */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    double p = 13, q = 13;
    double n = p * q;

    double phi = (p - 1) * (q - 1);

    double e = 7;
    while (e < phi)
    {
        if (__gcd((int)p, (int)q) == 1)
        {
            break;
        }
        e++;
    }

    double d1 = 1 / e;
    double d = fmod(d1, phi);

    double m = 59;
    double c = fmod((pow(m, d)), n);

    double dc = fmod((pow(c, e)), n);

    cout << "p is " << p << endl;
    cout << "q is " << q << endl;
    cout << "n is " << n << endl;
    cout << "phi is " << phi << endl;
    cout << "message is " << m << endl;
    cout << "encrytped message is " << c << endl;
    cout << "Decrytped message is " << dc << endl;

    return 0;
}