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
    
    int row = 1;
    int col = 1;
    
    while(row <= n)
    {
        while(col <= n - row){
            cout << " ";
            col++;
        }
        col = 1;
        while(col <= row){
            cout << col;
            col++;
        }
        col=row-1;
        while(col>0){
            cout << col;
            col--;
        }
        col=1;
        cout << endl;
        row++;
    }

    return 0;
}
