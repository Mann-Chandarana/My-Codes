#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void abc()
    {
        cout << "abc() of class A" << endl;
    }
};

class B
{
public:
    void abc()
    {
        cout << "abc() of class B" << endl;
    }
};

class C : public A, public B
{
public:
    // void abc()
    // {
    //     cout << "abc() of class C" << endl;
    // }

    void abc()
    {
        cout << "Inside abc() of class C" << endl;
        A ::abc();
        B ::abc();
    }
};

int main()
{
    cout << endl;
    C obj1;
    obj1.abc();

    obj1.A::abc();
    obj1.B::abc();
    obj1.C::abc();

    cout << "\n\nMain end\n\n";
    return 0;
}