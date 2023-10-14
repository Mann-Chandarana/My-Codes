#include <iostream>
using namespace std;

class vehicle
{

public:
    float average;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class car : public vehicle
{
    string fuel_type;
    int no_of_vehicles;

public:
    void getdata(void)
    {
        cout << "Enter the type of the fuel " << endl;
        cin >> fuel_type;
        cout << "Enter the no of the vehicles " << endl;
        cin >> no_of_vehicles;
        cout << "Enter average of the vehicle " << endl;
        cin >> average;
    }
    void putdata(void)
    {
        cout << "Type of fuel is :" << fuel_type << endl;
        cout << "No of vehicles are :" << no_of_vehicles << endl;
        cout << "Average of the vehicle is :" << average << endl;
    }
};

class truck : public vehicle
{
    string fuel_type;
    int no_of_vehicles;

public:
    void getdata(void)
    {
        cout << "Enter the type of the fuel " << endl;
        cin >> fuel_type;
        cout << "Enter the no of the vehicles " << endl;
        cin >> no_of_vehicles;
        cout << "Enter average of the vehicle " << endl;
        cin >> average;
    }
    void putdata(void)
    {
        cout << "Type of fuel is :" << fuel_type << endl;
        cout << "No of vehicles are :" << no_of_vehicles << endl;
        cout << "Average of the vehicle is :" << average << endl;
    }
};
int main()
{
    car c[2];
    for (int i = 0; i < 2; i++)
    {
        c[i].getdata();
    }
    for (int i = 0; i < 2; i++)
    {
        c[i].putdata();
    }
    cout << endl;
    truck t[2];
    for (int i = 0; i < 2; i++)
    {
        t[i].getdata();
    }
    for (int i = 0; i < 2; i++)
    {
        t[i].putdata();
    }

    return 0;
}