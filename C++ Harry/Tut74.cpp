#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    // Function Objects(Functor): Function wrapped in a class so that it is avalaible like an object
    int arr[] = {1, 73, 64, 92, 54, 77};
    sort(arr, arr + 5);                 // Ascending order
    sort(arr, arr + 5, greater<int>()); // Descending order
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}