#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int age;
    bool gender;

public:
    /*
        Default Constructor.
    */
    student()
    {
        cout << "Default Constructor" << endl;
    } // Default constructor.

    /*
        Parameterized Constructor
    */

    student(string s, int a, int g)
    {
        cout << "Parameterized Constructor" << endl;
        name = s;
        age = a;
        gender = g;
    } //Parameterized COnstructor.

    /*
        Copy Constructor
    */

    student(student &s)
    {
        cout << "Copy Constructor" << endl;
        name = s.name;
        age = s.age;
        gender = s.gender;
    } //Copy Constructor.

    void getInfo()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Gender = " << gender << endl;
    }

    /*
        Destructor.
    */

    ~student()
    {
        cout << "Destructor called!" << endl;
    }
};

int main()
{

    student s1("Parth", 19, 0);
    student s2;
    student s3(s1); // OR we can write student s2 = s1; also.

    s3.getInfo();

    //student s3("Niraj");
    //Will give error.

    return 0;
}