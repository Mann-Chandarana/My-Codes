#include <bits/stdc++.h>
using namespace std;

class Student
{
    // All the data meembers are private. This is called fully encapsulated class.
private:
    int id;
    int age;
    int std;
    string name;
    string grades;

public:
    int getAge()
    {
        return this->age;
    }
};

int main()
{
    Student s1;

    cout << "Main end" << endl;
    return 0;
}