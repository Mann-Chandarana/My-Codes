#include <bits/stdc++.h>
using namespace std;
/*
    [A]     [B]
     |       |
     |       |
     --     --
      |     |
      - [C]-
*/

class A
{
public:
    void speaking()
    {
        cout << "Speaking" << endl;
    }
};

class B
{
protected:
    string song = "See you again";

public:
    void listening()
    {
        cout << "Listening " << song << endl;
    }
};

class C : public A, protected B
{
public:
    void functionOfC()
    {
        listening();
    }
};

int main()
{
    C obj;
    // obj has inherited A using public mode and B using protected mode.
    // speaking() of A will be public in C and listening() of B will be protected in C.

    obj.speaking();
    // obj.listening(); // Gives error as listening() is protected in C.
    obj.functionOfC();

    return 0;
}