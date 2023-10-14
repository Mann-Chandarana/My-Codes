#include <iostream>
using namespace std;

// This code is for basic knowlage in class and its data types.
// Access specifiers (private and public). Protacted is not discussed here.

class student
{
private:
    string name;
    int age;
    bool gender;

public:
    void getInfo()
    {
        cout << "Name = ";
        cin >> name;
        cout << "Age = ";
        cin >> age;
        cout << "Gender = ";
        cin >> gender;
    }

    void printInfo()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Gender = " << gender << endl;
    }
};

int main()
{
    /*
        Object
    */
    // student a;
    // a.name = "Parth";
    // a.age = 19;
    // a.gender = 0;

    /*
        Array of object.
    */

    student arr[3];

    for (int i = 0; i < 3; i++)
    {
        arr[i].getInfo();
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i].printInfo();
        cout << endl;
    }

    return 0;
}