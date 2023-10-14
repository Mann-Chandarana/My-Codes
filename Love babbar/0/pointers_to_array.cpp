#include <iostream>
#include <vector>
using namespace std;

// Pointers in function

/*
int temp = 100;

void fun(int *n)
{
    (*n)++;   
}

void fun2(int *n)
{
    *n = temp;
    cout << *n << endl;
    
    // *n = 500;
    (*n)++;
}
*/

/*
void updateAddress(int *p)
{
    // *p = (*p) + 1;
    p = p + 1;
    // *p = (*p) + 1;
    cout << "Inside: " << p << endl; // 124
}
*/

// IMP
/*
    void updateAddress(int *p)
    {
        
        *p = (*p) + 1; // This will upadte the value of n in main function.
        p = p + 1;
        cout << "Inside: " << p << endl; // 124
    }
    
    void updateAddress(int *p)
    {
        p = p + 1;
        *p = (*p) + 1; // This will not update the value of n in the main function.
        // Why? because p is already increamented. So, now p is not pointing to n.
        cout << "Inside: " << p << endl; // 124
    }
*/

// For 1D array
void printArray(int *arr,int n) // This is same as, void printArray(int arr[], int n){}
{
    for(int i=0;i<n;i++)
        cout << *(arr + i) << " ";
    cout << endl;
}
void getArray(int *arr,int n)
{
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
        // cin >> *(arr + i); // Both are same.
    }
}

/*
// For Matrix
void getMatrix(int **arr,int n,int m) // Error
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> arr[i][j];
}
void printMatrix(int **arr,int n,int m) // Error
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
*/

int main()
{
    /*
    int a = 5;
    int *ptr = &a;
    
    cout << a << endl;
    fun(&a);
    cout << a << endl;
    fun(ptr);
    cout << a << endl;
    
    int *ptr2 = &a;
    cout << endl << *ptr2 << endl;
    fun2(ptr2);
    cout << *ptr2 << endl;
    */
    
    /*
    int n = 5;
    int *p = &n;
    cout << "Before: " << p << endl; // For example 123
    cout << n << endl;
    updateAddress(p); // 123 is passed
    cout << "After: " << p << endl; // 123
    cout << n << endl;
    */
    
    int arr[5] = {1,2,3,4,5};
    printArray(arr,5);
    int arr2[5];
    getArray(arr2, 5);
    printArray(arr2,5);
    printArray(arr2 + 2,2); // This will send the address of arr2[2].
    
    // int arr3[3][3];
    // getMatrix(arr3,3,3); // Error
    // printMatrix(arr3,3,3); // Error
    
    return 0;
}
