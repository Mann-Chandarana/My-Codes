#include <bits/stdc++.h>
using namespace std;

// Default, Parameterized and Copy Constructor
class Hero
{
    string password;

public:
    int health;
    char level;
    char *name;

    void setPassword(string p)
    {
        password = p;
    }

    string getPassword()
    {
        return password;
    }

    void getAllVal()
    {
        cout << endl
             << "Name: " << name << endl
             << "Level: " << level << endl
             << "Health: " << health << endl;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    // Constructors:

    // Default Constructor
    Hero()
    {
        name = new char[100];
        cout << "Constructor is called...\n";
    }

    // parameterized constructor
    Hero(int h, char l)
    {
        level = l;
        health = h;
    }

    Hero(char l)
    {
        level = l;
        health = 0;
    }

    // Copy Constructor
    Hero(Hero &h)
    // NOTE: It is necessary to pass the object using reference.
    {
        char *ch = new char[strlen(h.name) + 1]; // (+ 1) is used for NULL character
        strcpy(ch, h.name); // To copy the value of h.name (not address) to ch.
        name = ch; // To store the address of ch to name.
        // name = h.name; // This is also shallow copy, As we are pointing to the same address.
        health = h.health;
        level = h.level;
    }

    // Destroctor
    ~Hero()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    /*
    Hero h1;
    h1.health = 87;
    h1.level = 'A';
    h1.setPassword("Hgd224cS");
    h1.getAllVal();
    cout << endl;

    Hero *h4 = new Hero(89, 'D');
    h4->getAllVal();
    delete h4;
    cout << endl;

    Hero h2(67, 'B');
    Hero h3('C');
    cout << endl;
    h2.getAllVal();
    cout << endl;
    h3.getAllVal();
    */

    // Hero h5(98, 'A');
    // h5.name = "abc";
    // Hero h6(h5);
    // // Or we can do this, Hero h6; h6 = h5; // Both ways work same.
    // Hero *h7 = new Hero(h6);
    // h5.getAllVal();
    // h6.getAllVal();
    // h7->getAllVal();
    // Explicite call for destructor.
    // h7->~Hero();

    // Understanding deep and shallow copy constructor
    // Default copy constructor uses shallow copy constructor
    Hero h8;
    h8.level = 'D';
    h8.health = 45;
    char name[10] = "Parth";
    h8.setName(name);
    h8.getAllVal();
    cout << endl;
    // Example of shallow copy
    Hero h9(h8);
    // h9 = h8; // We can use this for copy constructor too.
    h9.getAllVal();
    h8.name[0] = 'D';
    h8.health = 100;
    cout << h9.name << endl;   // This gets changed
    cout << h9.health << endl; // This stays as same before

    // All the instances of any objects gets destrcuted at the end of the program.
    // Destructor gets only called for objects created statically and not dynamically.
    // When we delete dynamically created object using "delete" keyword then only destructor for that object is called.

    cout << endl
         << endl
         << endl;
    return 0;
}