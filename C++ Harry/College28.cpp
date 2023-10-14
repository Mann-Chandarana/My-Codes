#include <iostream>
using namespace std;

class Celsius
{
    int temp;

public:
    Celsius() { cout << "Default Constructor is running" << endl; }
    Celsius(int a)
    {
        temp = a;
    }
    void display(void)
    {
        cout << "Your temperature is :\n"
             << temp << endl;
    }

    operator float()
    {
        cout << "Basic type conversion" << endl;
        return temp;
    }
};
int main()
{
    Celsius c1;
    c1 = 20;
    c1.display();

    Celsius s2(30);
    float temperature;
    s2.display();
    temperature = s2;

    return 0;
}
