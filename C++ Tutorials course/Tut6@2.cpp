#include <iostream>
#include <math.h>
using namespace std;

// bool isPrime(int num)
// {
//     for (int i = 2; i <= sqrt(num); i++)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     for (int i = a; i <= b; i++)
//     {
//         if (isPrime(i))
//         {
//             cout << i << endl;
//         }
//     }

//     return 0;
// }

/////////Fibenacc sequence
void fib(int num)
{
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    for (int i = 1; i <= num; i++)
    {
        cout << t1 << endl;
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}
int main()
{
    int n;
    cin >> n;

    fib(n);
    return 0;
}
