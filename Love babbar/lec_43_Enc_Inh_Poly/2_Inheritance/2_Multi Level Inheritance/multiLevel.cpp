#include <bits/stdc++.h>
using namespace std;

// [A] -> [B] -> [C] -> [D] -> ...

class Animal
{
public:
    int age;
    int weight;
    void speaking()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    string breed = "breed_temp_name";
    string getBreed()
    {
        return this->breed;
    }
};

class Puppy : public Dog
{
public:
    string name = "temp_name";

    void printAll()
    {
        cout << age << endl
             << weight << endl
             << breed << endl
             << name << endl;
    }
};

class smallPuppy : public Puppy
{
};

class extraSmallPuppy : private smallPuppy
{
};

int main()
{
    Puppy p1;

    p1.printAll();
    smallPuppy sp;
    sp.speaking();

    extraSmallPuppy esp;
    // esp.speaking(); // Error as extraSmallPuppy is inherited using private mode.

    cout << "\n\nMain end...\n\n";
    return 0;
}