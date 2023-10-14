#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;
    virtual void getdata(void){};
    virtual void putdata(void){};
};

class Professor : public Person
{
public:
    int publication;
    static int cur_id;
    void getdata(void)
    {
        cin >> name;
        cin >> age;
        cin >> publication;
    }

    void putdata(void)
    {
        cout << name << " " << age << " " << publication << " " << cur_id << endl;
        cur_id++;
    }
};
int Professor::cur_id = 1;

class Student : public Person
{
public:
    int marks[6];
    static int cur_id;
    void getdata(void)
    {
        cin >> name;
        cin >> age;
        for (int i = 0; i < 6; i++)
        {
            cin >> marks[i];
        }
    }

    void putdata(void)
    {
        int temp = 0;
        for (int i = 0; i < 6; i++)
        {
            temp += marks[i];
        }
        cout << name << " " << age << " " << temp << " " << cur_id << endl;
        cur_id++;
    }
};
int Student::cur_id = 1;

int main()
{

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++)
    {

        cin >> val;
        if (val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
