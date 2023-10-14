#include <iostream>
using namespace std;

// Macros, global variables, inline functions and default arguments

// Global variable:
// If we want to share variables between functions.
// It is a bad practice to use non-static global variables. WHY? can be modified by any functions.

int n = 10;
char c;
string s = "abc";
// These are non static global variables. These can be modified by any function of the program.

static int i = 15;
// We can modify static variables also.
// Bad practice.

/*
void fun1()
{
    cout << "Inside fun1: " << n << endl;
    n = 0; // We can modify n here.
}

void fun2()
{
    cout << "Inside fun2: " << c << endl;
    c = 'z'; // We can modify c here.
}

void fun3()
{
    cout << "Inside fun3: " << s << endl;
    s = "fun3"; // We can modify s here.
}
*/

void fun4()
{
    cout << "Inside fun4: " << i << endl;
    i = 999;
}

int main()
{
    /*
    // cout << "Inside main: " << n << endl;
    // n++; // We can modify n here.
    // cout << "Inside main: " << n << endl;
    // fun1();
    // cout << n << endl;
    
    // cin >> c;
    // cout << c << endl;
    // c++;
    // fun2();
    // cout << c;
    
    // fun3();
    // cout << s << endl;
    // cin >> s;
    // cout << s;
    */
    
    // cout << i << endl;
    // i++;
    // cout << i << endl;
    // fun4();
    // cout << i << endl;
    
    
    return 0;
}
