/*Define a C++ Structure Rectangle with data member’s width and height. It has 
get_values() member functions to get the data from user and area() member 
functions to print the area of rectangle. Also create a C++ Class for the above 
program. Define both functions inside the class. Member function defined 
inside the class behaves like an inline function and illustrate the difference 
between C++ Structure and C++ Class.*/
#include <iostream>
using namespace std;

// struct rect
// {
//     int w, b;
//     void gets_value()
//     {
//         cout << "W= ";
//         cin >> w;
//         cout << "b= ";
//         cin >> b;
//     }
//     void area()
//     {
//         int ar = w * b;
//         cout << "area is\n" << ar << endl;
//     }
// } r;
// int main()
// {
//     r.gets_value();
//     r.area();
//     return 0;
// }

class rect
{
    int w, b;

public:
    void gets_value()
    {
        cout << "W= ";
        cin >> w;
        cout << "b= ";
        cin >> b;
    }
    void area()
    {
        int ar = w * b;
        cout << "area is\n"
             << ar << endl;
    }
};
int main()
{
    rect r;
    r.gets_value();
    r.area();
    return 0;
}