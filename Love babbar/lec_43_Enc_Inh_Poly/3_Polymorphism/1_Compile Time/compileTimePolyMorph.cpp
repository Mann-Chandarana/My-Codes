#include <bits/stdc++.h>
using namespace std;
/*
    Function overloading and Operator overloading
*/

// Function overloading
class A
{
public:
    void fun()
    {
        cout << "Hello Parth Rathod" << endl;
    }

    void fun(string name)
    {
        cout << "Hello " << name << endl;
    }

    // int fun()
    // {
    //     coout << "Hello Parth Rathod" << endl;
    // }
    // Function overloading

    int fun(int n)
    {
        cout << "Hello Parth Rathod" << endl;
        return n;
    }
};

// Operator Overloading
class B
{
public:
    int a, b;

    void operator+(B &obj)
    {
        // cout << "Output: " << obj.a - this->a << endl;

        cout << "Hello World" << endl;
    }

    void operator()()
    // () is an unary operator.
    {
        cout << "mein ek bracket hu " << this->a << endl;
    }

    void operator>>(int i)
    {
        this->a >>= i;
        this->b >>= i;

        cout << a << " " << b << endl;
    }

    void operator-=(B &o)
    {
        a -= o.a;
        b -= o.b;
        cout << a << " " << b << endl;
    }
};

int main()
{
    B o1, o2;
    o1.a = 4;
    o2.a = 7;
    o2.b = 1;

    o1 + o2;
    o1();
    o2();

    B o3;
    o3.a = 16;
    o3.b = 64;
    o3 >> 2;

    o3 -= o2;

    return 0;
}