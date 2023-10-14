#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getdata()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }
    void setdata(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};
int main()
{
    // Complex c1;
    // Complex *ptr = &c1;
    Complex *ptr = new Complex; // Another way of creating object
    // (*ptr).setdata(1, 54); is exactly same as
    ptr->setdata(1, 54);
    // (*ptr).getdata(); is as good as
    ptr->getdata();  // ptr jisko point kar raha hai uska object run kardo

    // Array of object
    Complex *ptr1 = new Complex[3];
    ptr1->setdata(1, 4);
    ptr1->getdata();
    (ptr1 + 1)->setdata(2, 55);
    (ptr1 + 1)->getdata();

    return 0;
}