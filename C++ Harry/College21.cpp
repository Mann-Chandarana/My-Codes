/*
Create a class Child having data members: name of the child and gender and a 
member function to get and print child data. Create another class Parent which is a 
friend class of child class. Class Parent have member function ReadChildData() 
which takes child’s object by reference as input argument and Reads the childs data 
and DisplayChildData() which takes childs object as argument and displays childs 
data. Use the concepts of Friend Class
*/

#include <iostream>
using namespace std;

class Parent;
class Child
{
    string name, gender;

public:
    void getData(void)
    {
        cout << "Enter child name " << endl;
        cin >> name;
        cout << "Enter child gender " << endl;
        cin >> gender;
    }
    void printData(void)
    {
        cout << "Child name is " << name << endl;
        cout << "Child gender is " << gender << endl;
    }
    friend class Parent;
};

class Parent
{
public:
    void ReadChildData(Child &o1)
    {
        cout << "Enter child name " << endl;
        cin >> o1.name;
        cout << "Enter child gender " << endl;
        cin >> o1.gender;
    }
    void displayChildData(Child o1)
    {
        cout << "Child name is " << o1.name << endl;
        cout << "Child gender is " << o1.gender << endl;
    }
};
int main()
{
    Child Harshil;
    Harshil.getData();
    Harshil.printData();
    cout << "\n";
    Parent Chhaya;
    Chhaya.ReadChildData(Harshil);
    Chhaya.displayChildData(Harshil);
    return 0;
}