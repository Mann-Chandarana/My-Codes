#include <iostream>

using namespace std;

int main()
{
    string name = "parth";
    string *ptr = &name;
    
    cout << name << " " << ptr << " " << *ptr << endl;
    
    // cout << *(ptr + 1) << endl;
    // ptr++;
    // cout << *ptr << endl;
    // *(ptr + 1) and ptr++, will give eror, or run infinite time.
    
    char *ptr2 = &name[0];
    cout << *ptr2 << endl;
    ptr2++;
    cout << *ptr2 << endl;
    ptr2 = &name[0];
    while(*ptr2)
        cout << *ptr2++ << " ";
    
    cout << endl << "test" << endl;

    return 0;
}
