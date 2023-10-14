/*Write a function called power () that takes two arguments: a double value for n and 
an int for p, and returns the result as double value. Use default argument of 2 for 
p, so that if this argument is omitted, the number will be squared. Write a main () 
function that gets values from the user to test this function.*/
#include <iostream>
using namespace std;
void power(int n1, int n2 = 2)
{
    int result = 1;
    for (int i = 0; i < n2; i++)
    {
        result *= n1;
    }
    cout << result;
}

int main()
{
    power(10);
    return 0;
}