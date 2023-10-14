#include <iostream>

using namespace std;

void print2d(int **arr, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void print1d(int *arr, int n)
{
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int *a = new int(8);
    cout << *a << endl;
    (*a)++; // Note *a++ will be interpreted as *(a++), new location not (+ 1) in value.
    cout << *a << endl;

    // Dynamic memory allocation to 1D array.
    int n = 4;
    int *arr = new int[n];
    for(int i=0;i<4;i++)
        arr[i] = i + 1;
    
    print1d(arr,n); // Passing 1d array to a function.
    
    // Dynamic memory allocation to a matrix.
    n = 3;
    int m = 3;
    int **arr1 = new int*[n];
    
    for(int i=0;i<n;i++)
        arr1[i] = new int[m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ele;
            cin >> ele;
            arr1[i][j] = ele;
        }
    }
    
    print2d(arr1,n,m); // passing 2d array to a function.

    return 0;
}
