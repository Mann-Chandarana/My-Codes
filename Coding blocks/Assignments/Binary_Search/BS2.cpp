///////////////////  Pivot element using binary search
///////////////////  Search in rotated array using binary search
///////////////////  Square root with precision of a number using binary search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int s, int e, int key)
{

    int start = s;
    int end = e;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int pivot_element(int *arr, int n)
{
    int s = 0, e = n - 1, mid;

    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
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

int search_in_rotated_array(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    int pivot = pivot_element(arr, n);
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        return binarySearch(arr, pivot, e, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

long long int sqrtInteger(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;

        if (square == n)
            return mid;

        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol)
{

    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int arr[6] = {5, 6, 7, 1, 2, 3};
    // cout << pivot_element(arr, 6) << endl;
    cout << search_in_rotated_array(arr, 6, 2) << endl;
    return 0;
}