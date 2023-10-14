#include <bits/stdc++.h>
using namespace std;

// MEthod overriding

class A
{
public:
    void abc()
    {
        cout << "Inside class A" << endl;
    }
};

class B : public A
{
public:
    void abc()
    {
        cout << "Inside class B" << endl;
    }
};

class C : public A
{
};

class D : public A
{
public:
    // If I make any function (With same name as function in parent class) it overrides the function made in parent class.  
    void abc()
    {
        // A::abc();
        cout << "Inside class D" << endl;
    }
    void abc(int a)
    {
        cout << "Inside class D with value " << a << endl;
    }
};

int main()
{
    A o1;
    B o2;
    C o3;
    D o4;

    o1.abc();
    o2.abc();
    o3.abc();
    o4.abc();
    o4.abc(5);

    return 0;
}