#include <iostream>
using namespace std;

// Macros, global variables, inline functions and default arguments

// Default arguments

// We can make start variable optional.
void print(int arr[],int n = 2,int start = 0) // We can put default value for any variable in function.
{
    for(int i=start;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

// CONDITION:
// void func1(int a,int b = 5,int c) // Error
// {
//     cout << "Fucniton";
// }

// We should give default arguments from the right most side.
// Right way to create func1() is, void func1(int a,int c,int b = 5).

int main()
{
    int arr[5] = {1,4,7,8,9};
    print(arr,5,2);
    // If the user doesn't want to give any starting position, take 0 by default.
    // So, print(arr,5) should print from 0 to sizze.
    print(arr,5); // start = 0. (Default value)
    
    print(arr); // n = 2 and start = 0. (Default values)

    const int i = 10;
    cout << i << endl;
    // i++; // Error. as i is a read-only variable
    cout << i << endl;
    
    return 0;
}

// Constant variables
// const int i = 10;
// i = i + 10; // error
