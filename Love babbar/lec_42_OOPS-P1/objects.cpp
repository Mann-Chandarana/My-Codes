#include <bits/stdc++.h>
#include "car.cpp" // car.cpp contains car and racecar classes.
using namespace std;

// We can include a class from another file also.
// For example car class is created in another file

class Hero
{
    // privat is the default type in class
    // public is the default type in structure
private:
    string password;

public:
    int age;
    int health = 100;
    string name;

    void setPassword(string s)
    {
        this->password = s;
        // this is a pointer that points to the class(In this case Hero).
    }
    string getPassword();
};

// Return_Type Class_Name :: Funcation_name(Passed_Variables){}
// :: is called scopre resoultion operator
string Hero ::getPassword()
{
    return password;
}

class Empty
{
    // No propteries
};

int main()
{
    Hero h1;
    Empty e1;

    // cout << "Size: " << sizeof(h1) << endl; // Sum of size of all the variables that are ther in the class.
    // cout << sizeof(e1) << endl; // Size of empty class is 1 byte.

    /*
    h1.age = 25;
    cout << h1.age << endl;

    cout << h1.health << endl;
    h1.setPassword("Ahej894Blm");
    cout << h1.getPassword() << endl;

    // Creating an object of a function that is not created in this file, but is created in other file
    car c1;
    c1.colour = "black";
    cout << c1.colour << endl;

    racecar r1;
    r1.trophies = 4;
    */


    // Dynamic memory allocation
    Hero *h2 = new Hero;
    // cout << sizeof(h2) << '\t' << sizeof(h1) << endl; // Ther is a difference between the size of an instance defined statically and dynamically.
    h2->age = 21;
    cout << h2->age << endl;
    cout << (*h2).age << endl;
    cout << (&h1)->age << endl; // We can do this too

    // NOTE: If we have variable then use '.' operator, If we have address of a variable then use '->' operator.

    cout << "\nMain end...\n";
    return 0;
}