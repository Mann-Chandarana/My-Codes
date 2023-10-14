#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;
    int col = 1;

    while (row <= n)
    {
        // 1st triangle
        while (col <= n - row + 1)
        {
            cout << col;
            col++;
        }

        // Star pattern1
        col = row - 1; // For start patterns
        while (col)
        {
            cout << "**";
            col--;
        }

        // // For start pattern2
        // col = 1;
        // while(col < row){
        //     cout << "*";
        //     col++;
        // }

        // 2nd triangle
        col = n - row + 1; // For second trangle
        while (col)
        {
            cout << col;
            col--;
        }

        col = 1;
        cout << endl;
        row++;
    }

    return 0;
}
