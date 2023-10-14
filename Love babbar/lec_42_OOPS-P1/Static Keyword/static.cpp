#include <bits/stdc++.h>
using namespace std;

// NOTE:
// We should not use static members with objects as they are created for the class and not for the objects.

class Hero
{
public:
    int age;
    int health;
    static int timeToComplete;
    static const int constInt;
    // static const int constInt = 67; // This also works.

    void fun()
    {
        timeToComplete = 65;
        age = 87;
    }

    static void hello()
    {
        cout << "Hello! You are in the static function hello()\n";
        // this->age = 10; // Would give an error
        timeToComplete = 987; // Static functions can only access and manipulate static variables.
        // age = 76; // Will give error
    }
    // NOTE: We can't use "this" keyword inside a static functions.
    // Why? "this" keyword is a pointer for current object.
    // As we know static functions are made for classes and not objects.
    // If we don't have any objects, how can we set values using "this" keyword.
};

// We have to initialize it outside of main function.
int Hero::timeToComplete = 20;
const int Hero ::constInt = 99;

int main()
{
    /*
        For static variables
    */

    cout << Hero::timeToComplete << endl;
    // This shows we can access static members without making any objects
    Hero::timeToComplete = 100;
    // This shows we can manipulate static members using class.

    Hero h1;
    cout << h1.timeToComplete << endl;
    // This shows, if we create any object, static member will have the value assigned to that static member
    h1.timeToComplete = 25;
    // This shows we can manipulate static members using any objects.

    Hero h2;
    cout << h2.timeToComplete << endl;

    cout << endl
         << endl;

    /*
        For static constant variables
    */

    cout << Hero::constInt << endl;
    // This shows we can access static const variable using class.

    cout << h1.constInt << endl;
    // This shows we can access static const variable using class.

    // h1.constInt = 89;
    // Hero::constInt++;
    // Both are giving errors as we can not modify constant variables.

    cout << endl
         << endl;
    /*
        Static functions
    */

    Hero::hello();
    h1.hello();
    h2.hello();

    cout << h2.timeToComplete << endl;

    cout << endl
         << endl;
    return 0;
}