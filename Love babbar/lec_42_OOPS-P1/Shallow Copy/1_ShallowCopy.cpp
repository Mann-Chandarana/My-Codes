#include <iostream>
using namespace std;

class Hero
{
public:
    int age;
    int *health;
    char *name;

    Hero()
    {
        name = new char[100];
        health = new int;
    }

    /*
    // This is also shallow copy.
    Hero(Hero &h)
    {
        name = h.name;
        health = h.health;
        age = h.age;
    }
    */

    void setName(char *name)
    {
        this->name = name;
    }
    void print()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Health: " << *health << endl;
    }
};

int main()
{
    Hero h1;
    char name[10] = "Parth";
    h1.setName(name);
    h1.age = 34;
    int health = 78;
    h1.health = &health;
    cout << "Values stored in h1:\n";
    h1.print();
    cout << endl
         << endl;
    Hero h2;
    h2 = h1;
    cout << "Values stored in h2 after copying it from h1:\n";
    h2.print();
    cout << endl;
    // Example of shallow copy
    (*(h1.health))++;
    h1.name[0] = 'D';
    h1.age = 46;
    cout << "Values stored in h2 after making changes in the values of h1:\n";
    h2.print();

    // If we change values in h1 it gets changes in h2 also. Why?
    // name and health are pointers in the object. h1 has name and health pointers pointing to a location.
    // If we copy h1 to h2, name and health in h2 will point to the same address name and health of h1 are pointing respectively.
    // If we make changes in any of the two (name and health) in any of the two objects (h1 and h2),
    // This will make changes in the value stored at the address.
    // Since both of the objects variables are pointing to same address, values get changed for both of the objects.

    return 0;
}
