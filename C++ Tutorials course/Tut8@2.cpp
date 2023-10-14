#include <iostream>
using namespace std;

// int linearSearch(int arr[], int n, int key)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == key)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int array[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }

//     int key;
//     cin >> key;

//     cout<<linearSearch(array,n,key)<<endl;
//     return 0;
// }

int binarySearch(int arr[], int n, int key)
{
    int s = 0; // Starting point
    int e = n; // ending point
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int key;
    cin >> key;

    cout << binarySearch(array, n, key) << endl;

    return 0;
}
///// Timecomplexity from screenshot