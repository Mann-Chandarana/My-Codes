#include <iostream>
using namespace std;

// Create array in heap memory
// Use heap memory by using new keyword.
// Dynamic allocation of memory in heap memory.

// In stack memory, it is called static memory allocation.
// In heap memory, it is called dynamic memory allocation.

void getArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cin >> arr[i];
}

void printArray(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    /*
    // Created a variable in heap memory.
    // int *i = new int;
    // cin >> *i;
    // cout << *i;
    
    int n;
    cin >> n;
    int *arr = new int[n]; // Created an array of size n (User defined at runtime) in heap memoy using new keyword.

    getArray(arr,n);
    printArray(arr,n);
    */

    int n;
    cin >> n;
    int *arr = new int[n];
    getArray(arr,n);
    printArray(arr,n);
    cout << *arr << " " << arr << endl;
    // free(arr);
    delete []arr;
    printArray(arr,n);
    cout << *arr << " " << arr << endl;
    
    // int arr[] = {1,2,3,4}; // This will end in conflicting declaration, even after we have released arr.
    getArray(arr,5);
    printArray(arr,5);
    

    return 0;
}
