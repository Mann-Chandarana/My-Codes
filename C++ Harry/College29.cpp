/* Create classes Celsius and Fahrenheit with float. Define appropriate member 
functions such that they support the statements in main( ): Celsius C1, C2=5.0; 
Fahrenheit F1, F2; F1=C2; C1=F2;Use the concepts of Type conversion from class 
type to class type.Write this Program in two ways. Define appropriate member 
function in class Celsius. Define appropriate member function in class 
Fahrenheit. */

#include <iostream>
using namespace std;

class Fahrenheit;
class Celsius
{
    float temp;

public:
    Celsius()
    {
        temp = 0;
    }

    Celsius(float a)
    {
        temp = a;
    }

    void display(void)
    {
        cout << "Your temperature of class celsuis is :\n"
             << temp << endl;
    }

    float tempReturn(void)
    {
        float t = temp;
        return t;
    }

    void operator=(Fahrenheit);
};

class Fahrenheit
{
    float tempee;

public:
    Fahrenheit()
    {
        tempee = 35;
    }
    void operator=(Celsius m)
    {
        tempee = m.tempReturn();
    }

    void display(void)
    {
        cout << "Your temperature of class Fahrenheit is :\n"
             << tempee << endl;
    }
    float tempReturn(void)
    {
        float t = tempee;
        return t;
    }
};

void Celsius::operator=(Fahrenheit m)
{
    temp = m.tempReturn();
}

int main()
{
    Celsius C1, C2;
    C2 = 5.0;
    C2.display();
    cout << "\n"
         << endl;

    Fahrenheit F1, F2;
    F1 = C2;
    F1.display();
    cout << "\n"
         << endl;
    C1 = F2;
    C1.display();

    return 0;
}