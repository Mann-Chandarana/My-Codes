////////////////// First Occurence using binary serach
////////////////// last Occurence using binary serach
////////////////// peak element using binary serach

#include <bits/stdc++.h>
using namespace std;

int first_Occurence(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid;
    int ans;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
    }
    return ans;
}

int last_Occurence(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int mid;
    int ans;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
    }
    return ans;
}

/////////////// Read love babbar notes for this question
int peak_element(int *arr, int n)
{
    int s = 0, e = n - 1, mid;

    while (s < e)
    {
        mid  = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{
    // int arr[6] = {1, 2, 3, 3, 4, 5};
    // cout << first_Occurence(arr, 6, 3) << endl;
    // cout << last_Occurence(arr, 6, 3) << endl;

    int arr[5] = {1, 2, 5, 3, 4};
    cout << peak_element(arr, 5) << endl;
    return 0;
}