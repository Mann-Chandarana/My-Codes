#include "bits/stdc++.h"
using namespace std;

int fact(int n)
{
    if (n <= 2)
        return n;
    return n * fact(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void reverseArr(int arr[], int start, int end)
{
    if (start >= end)
        return;
    swap(arr[start], arr[end]);
    reverseArr(arr, start + 1, end - 1);
    // We can write swap after the recursive call also.
}

bool isPalindrome(string s, int start)
{
    if (start >= s.length() / 2)
        return true;
    // Both of the given ways work.
    // bool check = true;
    // if (s[start] != s[s.length() - 1 - start])
    //     check = false;
    // return (check and isPalindrome(s, start + 1));
    if (s[start] == s[s.length() - start - 1])
        return isPalindrome(s, start + 1);
    return false;
}

int binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
        return mid;
    if (arr[mid] > key)
        return binarySearch(arr, start, mid - 1, key);
    return binarySearch(arr, mid + 1, end, key);
}

int main()
{
    // cout << "Factorial of 5: " << fact(5) << endl;
    // cout << "First 7 (starting from 0) fibonacci numbers:\n";
    // for (int i = 0; i < 8; i++)
    //     cout << fibonacci(i) << endl;

    // Reverse an array using recursion.
    int arr[] = {5, 2, 3, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    reverseArr(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // BS and palindrome strings recursively.
    string s1 = "abcdefghgiedcba";
    string s2 = "racecar";
    cout << isPalindrome(s1, 0) << endl;
    cout << isPalindrome(s2, 0) << endl;

    cout << "Binary Seach:\n";
    int arr1[] = {2, 4, 5, 7, 9, 10, 13, 14, 21, 30, 56, 99};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << binarySearch(arr1, 0, n1 - 1, 56) << endl;
    cout << binarySearch(arr1, 0, n1 - 1, 101) << endl;

    return 0;
}