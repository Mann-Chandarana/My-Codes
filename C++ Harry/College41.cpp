#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("Harshil.txt", ios::out);
    file << "India\n";
    int p = file.tellg();
    cout << p << endl;
    file.close();

    string name;
    fstream file3, file1;
    file3.open("Harshil.txt", ios::in);
    file3 >> name;
    file1.open("Mann.txt", ios::out);
    file1 << name;
    file.close();
    file1.close();

    fstream file2;
    file2.open("Mann.txt", ios::in);
    string name1;
    file2 >> name1;
    cout << name;

    return 0;
}