#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
// int sum(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int prevsum = sum(n - 1);
//     return n + prevsum;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << sum(n) << endl;

//     return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////
/// Calculate n raise to power p
// #include <iostream>
// using namespace std;

// int power(int n, int p)
// {
//     if (p == 0)
//     {
//         return 1;
//     }
//     int prevpower = power(n, p - 1);
//     return n * prevpower;
// }
// int main()
// {
//     int n, p;
//     cin >> n >> p;
//     cout<<power(n, p)<<endl;
//     return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////
// calculate factorial

// int factoria(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     //int prevfact = factoria(n - 1);
//     return n * factoria(n - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << factoria(n) << endl;
// }
///////////////////////////////////////////////////////////////////////////////////////////////
// Fibonacci
int fib(int n)
{
    if (n == 0 || n == 1) // base case
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout<<fib(n)<<endl;
    return 0;
}