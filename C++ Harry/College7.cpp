#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int *p, sizea;
    cout << "Enter the size::\n";
    cin >> sizea;
    p = new int[sizea]; // Dynamic memory allocation
    cout << "Enter the elements\n";
    for (int i = 0; i < sizea; i++)
    {
        cin >> p[i];
    }
    cout<<"Printing. . .\n";
    for (int i = 0; i < sizea; i++)
    {
        cout << p[i] + 2 << endl;
    }
    delete p; //it will free the memory

    return 0;
}
