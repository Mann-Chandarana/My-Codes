#include<iostream>
#include<conio.h>
using namespace std;

class A
{
public:
    int a;
    void funcA() { cout << "Function A in public section\n"; }

private:
    int b;
    void funcB() { cout << "Function B in private section\n"; }

protected:
    int c;
    void funcC() { cout << "Function C in protected section"; }
};

int main()
{
    // int n;
    // cin>>n;
    A obj;
    obj.funcA();
    obj.a = 5;

    // obj.funcB(),obj.funcC(),obj.b=6,obj.c=9 will give error.

    return 0;
}