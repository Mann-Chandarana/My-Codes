#include <iostream>

using namespace std;

// Recursive method
int findEle(int arr[], int n, int key,int low, int high)
{
    if(low > high)
        return -1;
    
    int mid = low + (high - low)/2;
    int ind;
    
    if(arr[mid] == key)
        return mid;
    
    if(arr[mid] > key)
        ind = findEle(arr,n,key,low,mid-1);
    else if(arr[mid] < key)
        ind = findEle(arr,n,key,mid+1,high);
        
    return ind;
}

// Iterative method
int findEleusingIteration(int arr[], int n, int key)
{
    int low = 0, high = n -1;
    
    while(high >= low)
    {
        int mid = low + (high - low)/2;
        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1;
}

int main()
{
    int arr[7] = {1,4,9,13,24,56,145};
    
    cout << "Using Recursion: " << findEle(arr, 7, 56, 0, 6) << endl;
    cout << "Using Iterative Method: " << findEleusingIteration(arr, 7, 56) << endl;

    return 0;
}
