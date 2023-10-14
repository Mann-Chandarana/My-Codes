#include <iostream>
using namespace std;

//This code is for basic knowlage in constructors.

class student
{
private:
    string name;
    int age;
    bool gender;

public:
    
    // Constructor.
    // It will automatically get called when the class is declared.
    // Note: Name of constructor is same as the name of class.
    
    // student(){
    //     cout<<"Default Constructor"<<endl;
    // }// Default constructor.

    student(string s,int a,int g){
        name =s;
        age = a;
        gender = g;
    }// Parametrized Constructor

    string getName(){
        return name;
    }

    void printName(){
        cout<<"Name = "<<name<<endl;
    }

    void setInfo(){
        cout<<"Age = ";
        cin>>age;
        cout<<"Gender = ";
        cin>>gender;
    }

    void getInfo()
    {
        cout << "Age = " << age << endl;
        cout << "Gender = " << gender << endl;
    }
};

int main()
{

    student s1("Parth",19,0);
    // In here s1 is of type student class.
    // when s1 is declared, constructor in the class will get called.

    //s1.getInfo();

    cout<<"Name = "<<s1.getName()<<endl; //Will print the name.
    s1.getInfo();

    //s1.printInfo();

    //student s2;
    //Will give error as we have created one constructor already.
    //If we make even one constructor compiler will not make default constructor.

    return 0;
}