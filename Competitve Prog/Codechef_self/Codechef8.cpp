#include <iostream>
#include <math.h>
using namespace std;
bool prime(int n)
{
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num1, num2, num3;
        cin >> num1 >> num2;

        for (int i = 1; ;i++)
        {
            if (prime(num1 + num2 + i))
            {
                num3 = i;
                break;
            }
        }
        
        cout << num3 << endl;
    }

    return 0;
}