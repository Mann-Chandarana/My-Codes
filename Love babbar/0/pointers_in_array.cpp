#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {11,12,13,14,15};
    // arr is the address of the first element of the array.
    
    int *ptr = arr;
    
    for(int i=0;i<5;i++)
    {
        cout << *ptr++ << " ";
        // ptr++;
    }
    cout << endl;
    
    cout << arr << endl;
    cout << *arr << endl;
    cout << arr + 1 << endl;
    cout << *(arr + 1) << endl;
    
    /*
        NEW:
    */
    int i=2;
    cout << i[arr] << " is same as " << arr[i] << endl;
    
    /*
        ERROR:
    */
    // cout << ++arr << endl; // arr is the address of the first element, we cannot update arr.
    
    // for(int i=0;i<5;i++)
    // {
    //     cout << *arr << endl;
    //     arr++; // Error, as we cannot update arr.
    // }
    
    /*
        Size:
    */
    // int arr[10];
    // cout << sizeof(arr) << endl;
    // int *ptr = arr;
    // cout << sizeof(ptr) << endl;
    // cout << sizeof(*ptr) << endl;

    cout << arr << "\t" << &arr[0] << "\t" << &arr << endl; // These three are same.
    int *ptr1 = arr;
    cout << ptr1 << "\t" << &ptr1 << "\t" << *ptr1 << endl; // These three are same.

    return 0;
}
