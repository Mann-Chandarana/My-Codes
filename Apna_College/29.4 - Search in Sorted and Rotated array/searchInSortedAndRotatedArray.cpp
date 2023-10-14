#include "bits/stdc++.h"
using namespace std;

int searchInARotatedArray(int arr[], int key, int left, int right)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (arr[mid] == key)
        return mid;

    if (arr[left] <= arr[mid])
    {
        if (key >= arr[left] and key <= arr[mid])
        {
            return searchInARotatedArray(arr, key, left, mid - 1);
        }
        return searchInARotatedArray(arr, key, mid + 1, right);
    }

    if (key >= arr[mid] and key <= arr[right])
    {
        return searchInARotatedArray(arr, key, mid + 1, right);
    }

    return searchInARotatedArray(arr, key, left, mid - 1);
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int key = 8, n = 8;

    cout << searchInARotatedArray(arr, key, 0, n - 1);

    return 0;
}


// bool bSearchInRotatedArray(int arr[],int n,int search){
//     int low = 0;
//     int high = n-1;
//     int mid;
//     while(low<high){
//         mid = (low+high)/2;
//         //cout<<"("<<low<<","<<mid<<","<<high<<")";
//         if(arr[mid]==search)return true;
//         if((arr[mid]<search && search<=arr[high]) || (arr[mid]>search && search>=arr[low])){
//             low = mid + 1;
//         }
//         if((arr[mid]<search && search>arr[high]) || (arr[mid]>search && search<arr[low])){
//             high = mid - 1;
//         }
//     }
//     return false;
// }