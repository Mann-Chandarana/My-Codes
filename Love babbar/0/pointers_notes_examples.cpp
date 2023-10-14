/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    // int a = 123;
    // int *ptr = 0;
    // ptr = &a;
    // cout << *ptr << endl;
    
    int arr[] = {1,2,3,4};
    int *p = &arr[0];
    cout << p << endl; // Address of 0th index of the array.
    
    char arr1[] = "abcde";
    char *p1 = &arr1[0];
    cout << p1 << endl; // Character array (Until NULL Character) from the pointed index.
    cout << &arr1[0] << " " << &p1 << endl; // Here, &arr1[0] (Same as arr1) will print the character array.
    cout << arr1[2] << " " << p1[2] << endl;
    p1++;
    cout << p1 << endl;
    (*p1)++;
    cout << p1 << endl;
    
    /*
        NOTE:
            cout works differently for int and char array.
    */

    return 0;
}
