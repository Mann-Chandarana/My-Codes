#include <iostream>
using namespace std;
class Celsius;
class Fahrenheit
{
    float temp;

public:
    void input(float x)
    {
        temp = x;
    }
    void output(void)
    {
        cout << "You entered " << temp;
    }
    friend void compare(Fahrenheit, Celsius);
};

class Celsius
{
    float temperature;

public:
    void input(float y)
    {
        temperature = y;
    }
    void output(void)
    {
        cout << "You entered " << temperature;
    }
    friend void compare(Fahrenheit, Celsius);
};

void compare(Fahrenheit o1, Celsius o2)
{
    float b = ((9.0 * o2.temperature) / 5.0) + 32.0;
    float a = o1.temp;
    if (a > b)
    {
        cout << "Temperature of object 1 is greater" << endl;
    }
    else
    {
        cout << "Temperature of object 2 is greater" << endl;
    }
}

int main()
{
    Fahrenheit a;
    a.input(99.0);
    a.output();
    cout << "\n";
    Celsius b;
    b.input(50.0);
    b.output();
    cout << "\n";
    compare(a, b);

    return 0;
}