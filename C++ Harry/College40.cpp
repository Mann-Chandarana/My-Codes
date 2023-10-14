#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileo;
    fileo.open("Harshil.txt", ios ::out);
    char arr[20] = "My name is Mann";
    fileo << arr;
    fileo.close();

    fstream filein;
    filein.open("Harshil.txt", ios::in);
    if (!filein)
    {
        cout << "Not able to open the file" << endl;
    }
    char c[20];
    int count = 0;
    char ch;
    while (!filein.eof())
    {
        //filein >> ch;
        count++;
        filein.getline(c, 20);
        cout << c << endl;
    }
    cout << count << endl;

    return 0;
}