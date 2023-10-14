#include <iostream>
using namespace std;

class Hospital
{
    int roll_no;
    string name;

public:
    void input(void)
    {
        cout << "Enter your roll_no: " << endl;
        cin >> roll_no;
        cout << "Enter your name: " << endl;
        cin >> name;
    }

    void output(void)
    {
        cout << "Your rollno is: " << roll_no << endl;
        cout << "Your name is: " << name << endl;
    }
};

class Ward : virtual public Hospital
{
    int Ward_number;

public:
    void getData(void)
    {
        input();
        cout << "Enter your ward number" << endl;
        cin >> Ward_number;
    }

    void printData(void)
    {
        output();
        cout << "Your ward number is " << Ward_number << endl;
    }
};

class Room : virtual public Hospital
{
    int bed_number;
    string nature_of_illness;

public:
    void getData(void)
    {
        cout << "Enter your bed number : " << endl;
        cin >> bed_number;
        cout << "Enter nature of illness : " << endl;
        cin >> nature_of_illness;
    }

    void printdata(void)
    {
        cout << "Your bed number is: " << bed_number << endl;
        cout << "Your nature of illness is: " << nature_of_illness << endl;
    }
};

class Patient : public Ward, public Room
{
};

int main()
{
    Patient P1;
    P1.Ward::getData();
    P1.Room::getData();
    P1.Ward::printData();
    P1.Room::printdata();
    return 0;
}