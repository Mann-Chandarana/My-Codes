#include <iostream>
using namespace std;

// Recursion - Day_1

void func(int i)
{
    if(i == 0)
        return;
    
    // cout << i << " "; // Head recursion. Will print from n to 1 in decreasing order.
    func(i - 1);
    cout << i << " "; // Tail recursion. Will print from 1 to n in increasing order.
}

void reverseArray(int *arr, int n, int start)
{
    if(start < 0 or start >= n)
        return;
    reverseArray(arr,n,start+1);
    cout << arr[start] << " ";
}

void getArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cin >> arr[i];
}

double negativePower(int a,int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1.0/a;
    
    return (1.0/a) * negativePower(a,n-1); 
}

double power(int a,int n)
{
    if(n == 1)
        return a;
    if(n == 0)
        return 1;
    if(n < 0)
        return negativePower(a,abs(n));
    
    return a*power(a,n-1);
}

long fact(int n)
{
    if(n == 0 or n == 1)
        return 1;
    if(n < 0)
        return -1;
    
    long x = fact(n - 1);
    return n * x; 
    
    cout << "Test" << endl;
    
    // We can do, 
    // return n * fact(n - 1); // Also
}

void recWithoutBaseCond(int n)
{
    cout << n << endl;
    recWithoutBaseCond(n - 1);
}

int findLog(int n,int base)
{
    if(n/base == 0)
        return 1;
    if(n/base == 1)
        return 1;
    
    return 1 + findLog(n/base, base);
}

int main()
{
    // // counting
    // int i;
    // cin >> i;
    // func(i);
    // cout << endl;
    
    // // Reverse print in array
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // getArray(arr,n);
    // reverseArray(arr,n,0);
    // cout << endl;

    // // Power function
    // int a,n;
    // cin >> a >> n;
    // cout << power(a,n) << endl;

    // // Factorial using Recursion
    // int n;
    // cin >> n;
    // cout << fact(n) << endl;

    // // Example of recursion function without any base condition:
    // int n = 10;
    // recWithoutBaseCond(n);

    // // function to find log
    // int n,base;
    // cin >> n >> base;
    // cout << findLog(n,base) << endl;


    cout << "Main end.." << endl;
    return 0;
}
