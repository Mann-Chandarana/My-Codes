#include <bits/stdc++.h>
using namespace std;

class Complex
{
public:
    int real, imag;

    void getComplex()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(Complex &c)
    {
        Complex ans;
        ans.real = real + c.real;
        ans.imag = imag + c.imag;

        return ans;
    }

    // We have to pass dummy int in post inc/dec operator
    // Why? both pre and post have same operator (++, --).
    // To distinguish between them we use dummy int in post operator;
    Complex operator++(int)
    {
        Complex ans;
        ans.real = real;
        ans.imag = imag;

        real++;
        imag++;

        return ans;
    }

    Complex operator++()
    {
        Complex ans;
        ans.real = ++real;
        ans.imag = ++imag;

        return ans;
    }
};

int main()
{

    Complex c1, c2;
    c1.real = 2;
    c1.imag = 6;

    c2.real = 14;
    c2.imag = -2;

    Complex c3;
    c3 = c1 + c2;
    cout << "c1 is: ";
    c1.getComplex();
    cout << "c2 is: ";
    c2.getComplex();

    cout << "\nAfter sum:\n";
    cout << "c3 is: ";
    c3.getComplex();

    Complex c4 = c3++;
    cout << "\nAfter post increament operator:\n";
    cout << "c3 is: ";
    c3.getComplex();
    cout << "c4 is: ";
    c4.getComplex();

    c4 = ++c3;
    cout << "\nAfter pre increament operator:\n";
    cout << "c3 is: ";
    c3.getComplex();
    cout << "c4 is: ";
    c4.getComplex();

    cout << "\n\nMain end...\n\n";
    return 0;
}