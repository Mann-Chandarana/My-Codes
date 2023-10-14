#include "bits/stdc++.h"
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

    // Copy constructor
    Hero(Hero &temp)
    {
        // Making copies of the variables that are stored by pointers to avoid shallow copy
        int *h = new int;
        *h = *(temp.health);

        char *n = new char[strlen(temp.name) + 1];
        strcpy(n, temp.name);

        // Assigning these new variables to the object variables
        this->health = h;
        this->name = n;
        this->age = temp.age;

        // In here we have created copies of the variables that are stored using pointers.
        // So, we store the address of the new variable(We got from copying) to the variables of object.
        // So, now all the variables (Created using pointer are pointing to different address.)
    }

    ~Hero()
    {
        cout << "Destructor called" << endl;
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
    Hero h2(h1);
    cout << "Values stored in h2 after copying it from h1:\n";
    h2.print();
    cout << endl;
    // Example of shallow copy
    (*(h1.health))++;
    h1.name[0] = 'D';
    cout << "Values stored in h2 after making changes in the values of h1:\n";
    h2.print();

    return 0;
}
