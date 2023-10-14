#include <iostream>
using namespace std;
///// Pointer
// int main()
// {
//     int arr[] = {10, 20, 30};
//     cout << *arr << endl;
//     int *ptr = arr;
//     for (int i = 0; i < 3; i++)
//     {
//         cout << *ptr;
//         cout << *(arr + i);
//         ptr++;
//     }

//     return 0;
// }
///// Pointer to Pointer
int main()
{
    int a = 10;
    int *p;
    p = &a;
    cout << *p << endl;
    int **q = &p;
    cout << *q << endl;
    cout << **q << endl;
    return 0;
}