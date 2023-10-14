#include <iostream>
using namespace std;

class Number
{
    int num;

public:
    void input()
    {
        cout << "Enter the number\n";
        cin >> num;
    }
    ////////////////////////////////////////////////////
    void output()
    {
        cout << "Your number is " << num << endl;
    }
    ////////////////////////////////////////////////////
    Number(){};
    ////////////////////////////////////////////////////
    Number(int n)
    {
        num = n;
    }
    ////////////////////////////////////////////////////
    Number(Number &a)
    {
        Number obj;
        obj.num = a.num;
    };
    ////////////////////////////////////////////////////
    Number operator++(void)
    {
        Number t;
        t.num = ++num;
        return t;
    }
    ////////////////////////////////////////////////////
    Number operator-(void)
    {
        Number b;
        b.num = -num;
        return b;
    }
};
int main()
{
    Number N1(45), N2;
    N1.output();
    N2 = -N1;
    N2.output();
    N2 = ++N1;
    N2.output();

    return 0;
}