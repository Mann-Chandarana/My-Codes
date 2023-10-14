#include <iostream>
using namespace std;

class Fun
{
public:
    void operator()(string s)
    {
        cout << "Having Fun with " << s;
    }
};

int main()
{
    Fun f;      /// Constructor
    f("C++");   //// Overload () operator = Function call where f is an object

    return 0;
}