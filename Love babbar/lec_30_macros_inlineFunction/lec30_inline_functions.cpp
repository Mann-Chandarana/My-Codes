#include <iostream>
using namespace std;

// Macros, global variables, inline functions and default arguments

// Inline functions

void func(int a,int b)
{
    cout << ++a << " " << ++b << endl;
}


// Create inline function using inline keyword
// Condition: Function should be of 1 line only.
// If the function is of 2-3 lines, then it depends upon the compiler.
// If >3, then cannot become inline function.

// Inline functions work in same way as Macros

inline int getMax(int& a,int &b)
{
    return (a>b) ? a : b;
}

int main()
{
    int a = 1, b = 2;
    // func(a,b);
    
    int ans = 0;
    // ans = (a > b) ? a : b;
    ans = getMax(a,b);
    cout << ans << endl;
    
    a += 3;
    b += 1;
    
    // ans = (a > b) ? a : b;
    ans = getMax(a,b);
    cout << ans << endl;
    
    return 0;
}
