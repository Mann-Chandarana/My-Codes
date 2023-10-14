///// last occurence

#include <iostream>
using namespace std;

int last_index(int *arr, int n, int key,int i)
{
    if (i==n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        int bi = last_index(arr, n , key,i+1);
        if (bi != -1)
        {
            return bi;
        }
        else
        {
            return i;
        }
    }
    return last_index(arr, n, key,i+1);
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

    cout << last_index(arr, n, key,0) << endl;

    delete[] arr;

    return 0;
}