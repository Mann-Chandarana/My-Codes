/// Double slided arrow

#include <iostream>
using namespace std;

void drawPattern(int N)
{
    int n = N;
    int row = 1;

    
    int nst = 1;

    int space_1 = n - 1;
    int space_2 = -1;
    int val1 = row;
    int val2 = 1;

    while (row <= n)
    {

        
        int csp1 = 1;
        while (csp1 <= space_1)
        {
            cout << " "
                 << " ";
            csp1 = csp1 + 1;
        }

        
        int cst1 = 1;
        while (cst1 <= nst)
        {
            cout << val1 << " ";
            val1 = val1 - 1;
            cst1 = cst1 + 1;
        }

       
        int csp2 = 1;
        while (csp2 <= space_2)
        {
            cout << " "
                 << " ";
            csp2 = csp2 + 1;
        }

    
        if (row != 1 && row != n)
        {
            int cst2 = 1;
            while (cst2 <= nst)
            {
                cout << val2 << " ";
                val2 = val2 + 1;
                cst2 = cst2 + 1;
            }
        }
        cout << endl;

        if (row <= n / 2)
        {
            nst = nst + 1;
            space_1 = space_1 - 2;
            space_2 = space_2 + 2;
            val1 = row + 1;
            val2 = 1;
        }
        else
        {
            nst = nst - 1;
            space_1 = space_1 + 2;
            space_2 = space_2 - 2;
            val1 = n - row;
            val2 = 1;
        }
        row = row + 1;
    }
}

int main()
{
    int N;
    cin >> N;

    drawPattern(N);

    return 0;
}
           