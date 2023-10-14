#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////
// Sorting of arrays

// bool sorted(int arr[], int n)
// {
//     if(n==1)
//     {
//         return true;
//     }
//     int restarray = sorted(arr + 1, n - 1);
//     return (arr[0] < arr[1] && restarray);
// }
// int main()
// {
//     int arr[] = {1, 5, 43, 36};
//     cout << sorted(arr, 4) << endl;
//     return 0;
// }

//////////////////////////////////////////////////////////////
// Printing in decreasing order
// void dec(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }

//     cout << n << endl;
//     dec(n - 1);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     dec(n);
//     return 0;
// }
// Printing in increasing order
// void inc(int n)
// {
//     if (n == 0)
//     {
//         return;
//     }
//     inc(n - 1);

//     cout << n << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     inc(n);
//     return 0;
// }
//////////////////////////////////////////////////////////////
// Searching an array
int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }

    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 7, 8};
    cout << firstocc(arr, 6, 0, 2)<<endl;
    cout << lastocc(arr, 6, 0, 2);
    return 0;
}