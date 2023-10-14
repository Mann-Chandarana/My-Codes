#include <iostream>
using namespace std;

// Recursion Day_3

void getArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
        cin >> arr[i];
}

bool isSorted1(int *arr,int n,int start = 0) // My solution
{
    if(start == n)
        return true;
    
    if((start != n - 1) and (arr[start] > arr[start + 1]))
        return false;
        
    return isSorted1(arr,n,start + 1);
}

bool isSorted2(int *arr,int size) // Online solution
{
    if(size == 0 or size == 1) // Here size variable is taken as the size and not the index.
        return true;
        // So, if the size if either 0 or 1 then the array is sorted.
    
    if(arr[size - 1] < arr[size - 2])
        return false;
    
    return isSorted2(arr, size - 1);
}

bool isSorted3(int *arr,int size) // Love babbar solution
{
    if(size == 0 or size == 1)
        return true;
    if(arr[0] > arr[1])
        return 0;
        
    return isSorted3(arr + 1, size - 1);
}

int sumInArray1(int *arr,int n)
{
    if(n == 0)
        return 0; // This condition is not required.
    if(n == 1)
        return arr[0];
    
    return arr[n - 1] + sumInArray1(arr, n - 1);
}

int sumInArray2(int *arr,int size)
{
    if(size == 1)
        return arr[0];
    
    return arr[0] + sumInArray2(arr + 1, size - 1);
}

void print(int *arr, int size)
{
    cout << "Size of the array is " << size << endl;
    for(int i=0;i<size;i++) cout << arr[i] << " ";
    cout << endl;
}

bool linearSearch(int *arr, int size,int &target)
{
    // print(arr,size); // To get better understanding of how linear search (In recursion) works
    if(size == 0)
        return false;
    
    if(arr[0] == target)
        return true;
    
    return linearSearch(arr + 1, size - 1, target);
}

void printInWindow(int *arr,int& start,int& end)
{
    cout << "Size of the array is " << end - start + 1 << endl;
    for(int i=start;i<=end;i++) cout << arr[i] << " ";
    cout << endl;
}

bool binarySearch(int *arr, int start,int end,int target)
{
    // printInWindow(arr,start,end); // To get better understanding of how binary search (In recursion) works
    // Base condition
    if(start > end)
        return false;
        
    // Processing
    int mid = start + (end - start) / 2;
    // Base condition
    if(arr[mid] == target)
        return true;
    
    // Recursive functions
    if(arr[mid] > target)
        return binarySearch(arr,start,mid-1,target);
    else
        return binarySearch(arr,mid+1,end,target);
    
}

int main()
{
    // // Is array sorted?
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // getArray(arr,n);
    // cout << isSorted1(arr,n) << endl;
    // cout << isSorted2(arr,n) << endl;
    // cout << isSorted3(arr,n) << endl;
    
    // // Sum of all elements of array:
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // getArray(arr,n);
    // cout << sumInArray1(arr,n) << endl;
    // cout << sumInArray2(arr,n) << endl;
    
    // // Linear search in an array:
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // getArray(arr,n);
    // int target;
    // cin >> target;
    // cout << linearSearch(arr,n,target) << endl;
    
    // // Binary search in an array: (Array must be in sorted order)
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // getArray(arr,n);
    // int target;
    // cin >> target;
    // int start = 0, end = n - 1;
    // cout << binarySearch(arr, start, end,target) << endl;
    
    
    cout << "Main end..." << endl;
    return 0;
}
