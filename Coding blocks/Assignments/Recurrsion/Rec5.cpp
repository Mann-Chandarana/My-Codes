///// All index problem

#include <iostream>
using namespace std;

void last_index(int *arr, int n, int key, int i)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == key)
    {
        cout << i << " ";
    }
    last_index(arr, n, key, i + 1);
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

    last_index(arr, n, key, 0);

    delete[] arr;

    return 0;
}