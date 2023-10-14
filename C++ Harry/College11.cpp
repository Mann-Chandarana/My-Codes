/*Write a function called tonLarge() that takes two integer arguments call by
reference and then sets the larger of the two numbers to 100 using Return by 
reference. Write a main() program to exercise this function.*/
#include <iostream>
using namespace std;
int &tonLarge(int &num1, int &num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}
int main()
{
    int x, y;
    cin >> x >> y;
    tonLarge(x, y) = 100;
    cout << "x= " << x << " y= " << y;
    return 0;
}

// void sum(int x, int y = 10)/////Default value cant be first argument
// {
//     int sum = x + y;
//     cout << "Sum is:" << sum;
// }
// int main()
// {
//     int x;
//     cin >> x ;
//     sum(x);
//     return 0;
// }
