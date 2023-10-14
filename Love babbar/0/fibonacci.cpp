/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0;
    int b = 1;
    
    for(int i=0;i<n;i++)
    {
        if(i == 0)
            cout << a << " ";
        else if(i == 1)
            cout << b << " ";
        else{
            int temp = a + b;
            cout << temp << " ";
            a = b;
            b = temp;
        }
        // cout << i << " ";
    }
}
