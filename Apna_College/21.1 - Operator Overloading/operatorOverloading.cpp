#include <iostream>
using namespace std;

// This code is on brief explanation of operator overloading.

class complex
{
public:
    int real, img;

    complex(int r, int i)
    {
        real = r;
        img = i;
    }
    complex(){
        real = 0;
        img = 0;
    }

    void getValue()
    {
        cout << real << " + i(" << img << ")" << endl;
    }

    //Operator overloading
    bool operator == (complex c){ // Here we can also wriet (complex &c). Pass by reference.
        if(c.img == img && c.real == real)
            return true;

        else    
            return false;
    }
    //Return_tpye  operator(Key_word)  Operator__Symbol  (Class  Pass_by_reference)

    complex operator + (complex c){ //OR complex operator + (complex &c)
        complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;

        return temp;
    }
};

int main()
{
    complex c1(3, 4);
    complex c2(3, 4);

    if (c1 == c2)
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not same" << endl;

    complex c3 = c1 + c2;
    c3.getValue();

    return 0;
}