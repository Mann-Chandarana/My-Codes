#include <iostream>
using namespace std;
// To know the bit at the given position

// int getBit(int n, int pos) // us position per konsa bit hai
// {
//     return (n & (1 << pos)) != 0;
// }

// int main()
// {
//     cout << getBit(5, 2) << endl;
//     return 0;
// }

// Set Bit // we have to add bit at a given position
// int SetBit(int n, int pos)
// {
//     return (n | (1 << pos));
// }

// int main()
// {
//     cout << SetBit(5, 1) << endl;
//     return 0;
// }

// Clear bit // To remove bit from the given position
// int ClearBit(int n, int pos)
// {
//     int mask = ~(1 << pos);
//     return (n & mask);
// }

// int main()
// {
//     cout << ClearBit(5, 2) << endl;
//     return 0;
// }

// Update bit // To update a bit at a given position 

int updateBit(int n, int pos,int value)
{
    int mask = ~(1 << pos);
    return (n & mask);
    return (n | (value << pos));
}

int main()
{
    cout << updateBit(5, 1,1) << endl;
    return 0;
}