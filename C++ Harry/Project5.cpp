#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////////////////////////////////////////////////
// Created by - Mann Chandarana
// Roll no - 20CS011
class Data
{
    string name, gender;
    int age;

public:
    void getdata(string s, int a, string gen)
    {
        name = s;
        age = a;
        gender = gen;
    }
    void display(void)
    {
        cout << "Your name is : " << name << endl;
        cout << "Your age is : " << age << endl;
        cout << "Your gender is : " << gender << endl;
    }
};
////////////////////////////////////////////////////////////////////////////
int main()
{
    Data A;
    A.getdata("Mann", 18, "Male");
    cout << endl;
    ////////////////////////////////////////////////////////////
    fstream file;
    file.open("Mann.txt", ios::out | ios::binary);
    file.write((char *)&A, sizeof(A));
    cout << "****************************************************************" << endl;
    cout << "Congrats your object is successfully written in the file " << endl;
    cout << endl;
    file.close();
    /////////////////////////////////////////////////////////////
    Data B;
    cout << "Reading the object from the file " << endl;
    cout << endl;
    fstream file1;
    file1.open("Mann.txt", ios::in);
    file1.read((char *)&B, sizeof(B));
    B.display();
    cout << "****************************************************************" << endl;
    file1.close();
}