#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void insertionSort(int *arr, int n, int start)
{
    if (start == n)
        return;

    for (int i = start; i > 0; i--)
    {
        if (arr[i] < arr[i - 1])
            swap(arr[i], arr[i - 1]);
        else
            break;
    }

    insertionSort(arr, n, start + 1);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    print(arr, n);
    insertionSort(arr, n, 0);
    print(arr, n);

    return 0;
}