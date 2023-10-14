#include <iostream>
#include <fstream>
using namespace std;

class name
{
    string name;
    int age;

public:
    void getdata(string s, int a)
    {
        name = s;
        age = a;
    }

    void print(void)
    {
        cout << "Name is " << name << endl;
        cout << "Your age is " << age << endl;
    }
};
int main()
{
    name obj1;
    obj1.getdata("Harshil", 10);
    fstream file;
    file.open("Harshil.txt", ios::binary | ios::out | ios::in);
    file.write((char *)&obj1, sizeof(name));

    file.seekg(0);
    name obj2;
    file.read((char *)&obj2, sizeof(name));
    obj2.print();

    return 0;
}