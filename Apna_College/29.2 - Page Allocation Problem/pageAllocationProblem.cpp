#include "bits/stdc++.h"
using namespace std;
// Allocate minimum pages.

bool isPossible(int arr[], int n, int totalStudentsAvailable, int min)
{
    int studentsRequired = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            return false;

        if (sum + arr[i] > min)
        {
            studentsRequired++;
            sum = arr[i];
            // If min is 6, and current student has 5 pages right now, and arr[i] is 2 then we cannot give it to student 1.(5 + 2 > 6).
            // So we give that arr[i] to the next student.

            if (studentsRequired > totalStudentsAvailable)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }

    return true;
}

int allocateMinimumPages(int arr[], int n, int m) // n is total number of books,m is total number of students.
{
    if (m > n) // If there are more studetns than total books, then we cannot distribute the book.
        return -1;

    int sum = 0,k=0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        k=max(k,arr[i]);
    }

    int start = k, end = sum, ans = -1;
    // start = 0, if we give 0 book to a student.
    // end = sum, if we give all the books to a student.
    // which is not going to happen.

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    cout << "The minimum number of pages: " << allocateMinimumPages(arr, n, m) << endl;

    return 0;
}