#include <iostream>
using namespace std;

// Macros, global variables, inline functions and default arguments

// Macros:
#define PI 3.14
#define ll long
#define loop(i,n) for(;i<n;i++)
#define greater(a,b) if(a > b) cout << a << endl; else cout << b << endl;
#define minimum(a,b) (((a) < (b)) ? (a) : (b)) 

int main()
{
    // Macros:
    int r = 5;
    cout << "PI: " << PI << endl;
    double area = PI * r * r;
    cout << "Area: " << area << endl;
    double volume = (4/3.0) * PI * r * r * r;
    cout << "Volume: " << volume << endl;
    
    // We can do double PI = 3.14; also. But it takes extra storage in the memory,
    // and affects (effect is minimal) the speed of the program.
    
    // PI = PI + 1; // We cannot do that.
    // int PI = 6; // Error
    // double PI = 8.45; // Error
    
    cout << "Size of long: " << sizeof(ll) << endl;
    
    int i=2;
    loop(i,9) cout << i << " ";
    cout << endl;
    
    greater(5,7)
    cout << "Minimum values between 1205 and 342 is " << minimum(1205,342);
    
    return 0;
}
