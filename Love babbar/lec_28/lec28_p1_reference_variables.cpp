#include <iostream>
#include <vector>
using namespace std;

void passByValue(int i)
{
    i++;
}

void passByReference(int &n)
{
    n++;
}

/*
int& fun1(int n)
{
    int i = n;
    int &a = i;
    a++;
    return a;
} // In this case the compiler might give a warning.
// n is a copy, i is created in the function => both n and i will disappear after the function fun1() is ended.
// a is referenced to i. So, a will also disapper.

int& fun2(int &n)
{
    int &a = n;
    a++;
    return a;
}
*/

int main()
{
    // Creating a reference variable.
    int i = 5;
    int &j = i; // j is a reference variable for i.
    cout << i << " " << j << endl;
    i++;
    cout << i << " " << j << endl;
    j++;
    cout << i << " " << j << endl;

    i = 5;
    cout << endl
         << i << endl;

    // Why do we need reference variables.
    passByValue(i);
    cout << "After pass by value: " << i << endl;
    passByReference(i);
    cout << "After pass by reference: " << i << endl;

    /*
        // Returning a reference variable from a function:
        // It is a bad practice.
        int n = 5;
        cout << "\n";
        cout << "n: " << n << endl;
        cout << fun1(n) << " " << n << endl;
        cout << "n: " << n << endl;
        cout << fun2(n) << " " << n << endl;
    */

    return 0;
}
