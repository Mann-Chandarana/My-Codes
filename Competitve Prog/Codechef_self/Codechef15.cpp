#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, *arr;
    cin >> t;

    while (t--)
    {
        arr = new int[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + 4);
        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
        {
            cout << "0" << endl;
            continue;
        }
        if ((arr[0] == arr[1] && arr[1] == arr[2]) || (arr[1] == arr[2] && arr[2] == arr[3]))
        {
            cout << "1" << endl;
            continue;
        }
        else
        {
            cout << "2" << endl;
            continue;
        }
        
    }

    return 0;
}