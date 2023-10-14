#include <iostream>
using namespace std;

// First and Last occurence using binary search

int firstOccurence(int *arr,int n,int target,int &start,int &end)
{
    if(start > end)
        return -1;
    
    int mid = start + (end - start) / 2;
    if(arr[mid] == target and (mid == 0 or arr[mid - 1] != target))
        return mid;
    
    if(arr[mid] < target) {
        start = mid + 1;
        return firstOccurence(arr,n,target,start,end);
    }
    else{ 
        end = mid - 1;
        return firstOccurence(arr,n,target,start,end);
    }
    
}

int lastOccurence(int *arr,int n,int k,int &start,int &end)
{
    if(start > end)
        return -1;
    
    int mid = start + (end - start)/2;
    
    if(arr[mid] == k and (mid == n - 1 or arr[mid + 1] != k))
        return mid;
   	
    if(arr[mid] > k)
    {
        end = mid - 1;
        return lastOccurence(arr,n,k,start,end);
    }
    else
    {
        start = mid + 1;
        return lastOccurence(arr,n,k,start,end);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    int target;
    cin >> target;
    int start =0, end = n - 1;
    
    cout << "First occurenece of " << target << " is " << firstOccurence(arr,n,target,start,end) << endl;
    start = 0, end = n - 1;
    cout << "Last occurenece of " << target << " is " << lastOccurence(arr,n,target,start,end) << endl;

    return 0;
}
