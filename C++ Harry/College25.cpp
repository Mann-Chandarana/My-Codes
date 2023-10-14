#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex(int a, int b)
    {
        real = a;
        img = b;
    }

    Complex(Complex &obj)
    {
        real = obj.real;
        img = obj.img;
    }

    Complex()
    {
        real = 0;
        img = 0;
    }
    void printData(void)
    {
        cout << "Your Complex number is " << real << " + i" << img << endl;
    }
    friend void operator-(Complex &);
};
void operator-(Complex &obj)
{
    obj.real = -obj.real;
    obj.img = -obj.img;
}
int main()
{
    Complex c1(5, 6);
    c1.printData();
    -c1;
    c1.printData();

    return 0;
}