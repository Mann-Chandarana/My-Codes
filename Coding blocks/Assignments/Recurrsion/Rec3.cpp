///////////////// First Index

#include <iostream>
using namespace std;

int first_index(int *arr, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return 0;
    }

    int i = first_index(arr + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

int main()
{
    int n, key;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> key;

    cout << first_index(arr, n, key) << endl;

    return 0;
}