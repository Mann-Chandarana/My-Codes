#include <iostream>
using namespace std;
//////////////////////////////////////////////
int search_rotated_arrayh(int arr[], int high, int low, int element)
{
    if (low >= high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == element)
    {
        return 1;
    }

    if (arr[low] <= arr[mid])
    {
        if (element >= arr[low] && element <= arr[mid])
        {
            search_rotated_arrayh(arr, mid - 1, low, element);
        }
        search_rotated_arrayh(arr, high, mid + 1, element);
    }
    if (element >= arr[mid] && element <= arr[high])
    {
        search_rotated_arrayh(arr, high, mid + 1, element);
    }
    return search_rotated_arrayh(arr, mid - 1, low, element);
}
//////////////////////////////////////////////
int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int  n = 8;

    cout << search_rotated_arrayh(arr, n-1,0,2);

    return 0;
}