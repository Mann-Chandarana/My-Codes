#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
    void getAll()
    {
        cout << "Height: " << height << endl
             << "Weight: " << weight << endl
             << "Age: " << getAge() << endl;
    }
};

class Male : public Human
{
public:
    string colour;

    void sleep()
    {
        cout << "He is sleeping..." << endl;
    }
};

class Female : public Human
{
public:
    string name;

    void study()
    {
        cout << "She is studying..." << endl;
    }
};

int main()
{
    Male m1;
    m1.age = 10;
    m1.height = 19;
    m1.setWeight(78);
    m1.colour = "Black";
    m1.getAll();
    m1.sleep();

    cout << "\n\n";

    Female f1;
    f1.age = 20;
    f1.setWeight(48);
    f1.height = 156;
    f1.name = "Ahskcaijs";
    f1.getAll();
    f1.study();

    cout << "\n\nMain end\n\n";
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Parent
{
private:
    int salary;
    string choice;

public:
    int height;
    string lastName;

    void setSalary(int s)
    {
        salary = s;
    }

    void getValParent()
    {
        cout << "Height: " << height << endl
             << "Last Name: " << lastName << endl
             << "Salary: " << salary << endl;
    }
};

class Child : public Parent
{
public:
    string childName;

    void getValChild()
    {
        cout << "Name: " << childName << endl
             << "Last Name: " << lastName << endl
             << "Height: " << height << endl;
    }
};

int main()
{
    Parent p1;
    p1.height = 180;
    p1.lastName = "Rathod";
    p1.setSalary(12000);

    p1.getValParent();

    Child c1;
    c1.childName = "Parth";
    c1.lastName = "Rathod";
    c1.height = 176;

    c1.getValChild();
    c1.getValParent();

    cout << "\n\nMain end...\n\n";
    return 0;
}
*/