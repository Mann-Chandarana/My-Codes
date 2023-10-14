/* Function overloading
- name of function are same
- no of argument or type of argument are different */

/*Define three functions named divide(). First function takes numerator and 
denominator as an input argument and checks it’s divisible or not, Second function 
takes one int number as input argument and checks whether the number is prime or 
not and Third function takes 3 float number as argument and finds out average of 
the numbers. Use concept of Function Overloading / static binding. */

#include <iostream>
using namespace std;
/// Functions overloading
void divide(int num, int deno)
{
    if (num % deno == 0)
    {
        cout << "Number is divisible\n";
    }
    else
    {
        cout << "Number is not divisible\n";
    }
}
void divide(int num)
{
    int count = 0;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Number is a prime number" << endl;
    }
    else
    {
        cout << "Number is not a prime number" << endl;
    }
}
void divide(float n1, float n2, float n3)
{
    float average = (n1 + n2 + n3) / 3;
    cout << average << endl;
}

int main()
{
    int n;
    cout << "Press\n1) for divide \n2) for prime or not\n3) for average\n ";
    cin >> n;
    if (n == 1)
    {
        int num, deno;
        cin >> num >> deno;
        divide(num, deno);
    }
    else if (n == 2)
    {
        int num;
        cin >> num;
        divide(num);
    }
    else if (n == 3)
    {
        float n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        divide(n1, n2, n3);
    }
    else
    {
        cout<<"Invalid choice"<<endl;
    }
    

    return 0;
}
