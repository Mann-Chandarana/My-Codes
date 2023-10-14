//////////////////// Minimum swap to sort the array

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int indexOf(vector<int> &arr, int ele)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

int miniswap(vector<int> &v, int n)
{
    vector<int> temp(v.begin(), v.end());
    sort(temp.begin(), temp.end());
    int swapp = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != temp[i])
        {
            swapp++;
            swap(v, i, indexOf(v,temp[i]));
        }
    }

    return swapp;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << miniswap(v, v.size()) << endl;

    return 0;
}