#include <iostream>
using namespace std;

class Num
{
    int a, b;

public:
    void input(int c, int d)
    {
        a = c;
        b = d;
    }
    void output(void)
    {
        cout << "First number is : " << a << endl;
        cout << "Second number is : " << b << endl;
    }
    Num operator-(Num obj)
    {
        Num obj1;
        obj1.a = a - obj.a;
        obj1.b = b - obj.b;
        return obj1;
    }
    bool operator==(Num obj)
    {
        if (a == obj.a && b == obj.b)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    Num N1, N2;
    int num1, num2;
    cout << "*****************************" << endl;
    cout << "Enter first number" << endl;
    cin >> num1;
    cout << "Enter second number" << endl;
    cin >> num2;
    N1.input(num1, num2);
    cout << "*****************************" << endl;
    cout << endl;
    //N1.output();
    ///////////////////////////////////////////////
    int num3, num4;
    cout << "*****************************" << endl;
    cout << "Enter first number" << endl;
    cin >> num3;
    cout << "Enter second number" << endl;
    cin >> num4;
    N2.input(num3, num4);
    cout << endl;
    //N2.output();
    cout << "*****************************" << endl;
    ///////////////////////////////////////////////
    Num N3;
    N3 = N1 - N2;
    cout << endl;
    N3.output();
    cout << endl;
    cout << "*****************************" << endl;
    //////////////////////////////////////////////
    if (N1 == N2)
    {
        cout << "Both are same" << endl;
    }
    else
    {
        cout << "Both are not same" << endl;
    }

    return 0;
}