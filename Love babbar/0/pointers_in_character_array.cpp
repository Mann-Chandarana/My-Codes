#include <iostream>
using namespace std;

// Pointers in character array.

int main()
{
    /*
    int arr[] = {1,2,3,4,5};
    // char ch[5] = "abcde"; // Error. last character should be a null character.
    char ch[6] = "abcde";
    // cout << arr << endl; // Will print address of the array.
    cout << ch << endl; // Will print entire charcter array.
    
    // IMP:
    // Implementation of cout function is different for int array and character array.
    
    char *ptr = &ch[0];
    cout << ptr << " " << &ptr << " " << &ch << endl;
    // ptr is same as ch. &ptr will store the address of ptr, &ch will store the address of ch.
    cout << *ptr << " " << *(ptr + 2) << endl;
    
    ptr++; // Now ptr will point to ch[1];
    ptr = ch; // Now ptr will point to ch[0];
    
    while(*ptr)
    {
        cout << *ptr++ << " ";
    }
    cout << endl;
    ptr = ch;
    
    char c = 'z';
    char *ptr1 = &c;
    cout << ptr1 << endl; // Will print characters in contiguous address until null character occurs.
    cout << *ptr1 << endl;
    cout << *(ptr1 + 1) << endl;
    */
    
    char ch[6] = "abcde";
    // char *c = "abcde"; // Never do this.
    cout << ch << endl;
    // cout << c << endl;
    char *ptr2 = &ch[0]; // This is same as, char *ptr2 = ch;
    cout << *ptr2 << endl;
    ptr2++;
    cout << *ptr2 << endl;
    char *ptr3 = ch;
    cout << *(ptr3+4) << endl;
    
    /*
    char n[100]  = "Parth Rathod";
    char *name = n;
    cout << name << endl;
    cout << (name+ 3) << endl;
    cout << &name[3] << endl;
    cout << name[3] << endl;

    O/P:
    Parth Rathod
    th Rathod
    th Rathod
    t
    */

    return 0;
}
