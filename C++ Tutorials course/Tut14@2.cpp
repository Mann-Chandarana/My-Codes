#include <iostream>
using namespace std;

// To check if a given number is power of 2

// bool ispowerof2(int n)
// {
//     return (n && !(n & n - 1));
// }
// int main()
// {
//     cout << ispowerof2(16) << endl;
//     return 0;
// }

// To count he number of ones in binary representation of a number
// int numberofones(int n)
// {
//     int count = 0;
//     while (n)
//     {
//         n = n & n - 1;
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     cout << numberofones(19) << endl;

//     return 0;
// }

// To generate all possible subset of a set
void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    subsets(arr, 4);
    return 0;
}