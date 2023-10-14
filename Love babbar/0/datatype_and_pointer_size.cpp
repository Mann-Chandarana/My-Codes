#include <iostream>

using namespace std;

int main()
{
    int num = 5;
    double d = 4.23;
    char ch = 'a';
    string name = "Parth";
    long num1 = 15348;
    bool check = false;
    float f = 3.4;
    
    int *p1 = &num;
    double *p2 = &d;
    char *p3 = &ch;
    string *p4 = &name;
    long *p5 = &num1;
    bool *p6 = &check;
    float *p7 = &f;
    
    // Size of different data types.
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of string: " << sizeof(string) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    
    cout << endl;
    // Size of pointers of all data types.
    cout << "Size of int pointer: " << sizeof(p1) << endl;
    cout << "Size of double pointer: " << sizeof(p2) << endl;
    cout << "Size of char pointer: " << sizeof(p3) << endl;
    cout << "Size of string pointer: " << sizeof(p4) << endl;
    cout << "Size of long pointer: " << sizeof(p5) << endl;
    cout << "Size of bool pointer: " << sizeof(p6) << endl;
    cout << "Size of float pointer: " << sizeof(p7) << endl;
    // Pointers always store address, so the size for any pointer is 8 bytes.

    return 0;
}
