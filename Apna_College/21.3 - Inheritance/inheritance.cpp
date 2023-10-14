#include <iostream>
using namespace std;

// It is possible to inherit attributes and methods from one class to another.
// One of the key principles of OOPS.

class parent
{
public:
    void fun_parent() { cout << "Function of parent class"; }
};

class child : public parent
{
public:
    void fun_child()
    {
        fun_parent();
    }
};

int main()
{
    int n;
    cin >> n;
    child obj;
    obj.fun_child();

    return 0;
}