#include <iostream>
using namespace std;

// Recursion Day_2

void func(int src, int dest)
{
    cout << "Source " << src << " destination " << dest << endl;
    
    if(src == dest)
    {
        cout << "Reached home" << endl;
        return;
    }
    src++;
    func(src, dest);
}

int fibonacciNumbers(int n)
{
    if(n == 1 or n == 2)
        return n - 1;
    
    return fibonacciNumbers(n - 2) + fibonacciNumbers(n - 1);
}

string convert(int n)
{
    switch(n)
    {
        case 0:
            return "zero";
            break;
        case 1:
            return "one";
            break;
            
        case 2:
            return "two";
            break;
            
        case 3:
            return "three";
            break;
            
        case 4:
            return "four";
            break;
        case 5:
            return "five";
            break;
        case 6:
            return "six";
            break;
        case 7:
            return "seven";
            break;
        case 8:
            return "eight";
            break;
        case 9:
            return "nine";
            break;
        default:
            return "";
    }
}

void sayDigit(int n)
{
    if(n == 0)
        return;

    int rem = n%10;
    
    sayDigit(n/10);
    cout << convert(rem) << " ";
}

int main()
{
    // // Basic for recursion
    // int src = 1;
    // int dest = 10;
    // func(src, dest);

    // // Fibonacci numbers
    // int n;
    // cin >> n;
    // cout << fibonacciNumbers(n) << endl;
    
    // // Say digit:
    // int n;
    // cin >> n;
    // sayDigit(n);
    // cout << endl;
    
    
    cout << "Main end..." << endl;
    return 0;
}

