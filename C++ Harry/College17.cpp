#include <iostream>
#include <string>
using namespace std;

class Gate
{
    int Registration_no;
    string name;
    string Examcentre;
    static int ECV_CNT;
    static int ECS_CNT;
    static int ECA_CNT;

public:
    void getData(void)
    {
        int choice;
        cout << "Enter Registration number is :" << endl;
        cin >> Registration_no;
        cout << "Enter your name is :" << endl;
        cin >> name;
        cout << "Press 1) For Surat 2) For Vadodara 3) For Ahmedabad : " << endl;
        cin >> choice;
        if (choice == 1)
        {
            Examcentre = "Surat";
            ECS_CNT++;
        }
        else if (choice == 2)
        {
            Examcentre = "Vadodara";
            ECV_CNT++;
        }
        else if (choice == 3)
        {
            Examcentre = "Ahmedabad";
            ECA_CNT++;
        }
        else
        {
            cout << "Invalid Choice !" << endl;
        }
    }

    void putData(void)
    {
        cout << "Your Registration number is " << Registration_no << endl;
        cout << "Your name is " << name << endl;
        cout << "Your exam center is " << Examcentre << endl;
    }

    void static getcount(void)
    {
        cout << "Total no of students in Examination center Surat : " << ECS_CNT;
        cout << "Total no of students in Examination center Vadodara : " << ECV_CNT;
        cout << "Total no of students in Examination center Ahmedabad : " << ECA_CNT;
    }
};

int Gate::ECV_CNT = 0;
int Gate::ECS_CNT = 0;
int Gate::ECA_CNT = 0;

int main()
{
    Gate Student[5];
    for (int i = 0; i < 5; i++)
    {
        Student[i].getData();
    }

    for (int i = 0; i < 5; i++)
    {
        Student[i].putData();
    }

    Gate::getcount();

    return 0;
}