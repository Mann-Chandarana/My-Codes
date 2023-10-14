#include <iostream>
using namespace std;

class Medicine
{
    string type, name;
    int date;

public:
    void getData(void)
    {
        cout << "Enter the name of the medicine" << endl;
        cin >> name;
        cout << "Enter the type of medicine" << endl;
        cin >> type;
    }

    void putData(void)
    {
        cout << "The name of the medicine :" << name << endl;
        cout << "The type of the medicine :" << type << endl;
    }
};

class Tablet : public Medicine
{
    int quantity, price;

public:
    void input(void)
    {
        getData();
        cout << "Enter the quantity of the tablet :" << endl;
        cin >> quantity;
        cout << "Enter the price of the tablet" << endl;
        cin >> price;
    }

    void output(void)
    {
        putData();
        cout << "The quantity of the tablet is : " << quantity << endl;
        cout << "The price of the medicine : " << price << endl;
    }
};

class syrup : public Medicine
{
    int quantity, dosage;

public:
    void input(void)
    {
        getData();
        cout << "Enter the quantity of the syrup" << endl;
        cin >> quantity;
        cout << "Enter the dosage of the syrup" << endl;
        cin >> dosage;
    }
    void output(void)
    {
        putData();
        cout << "The quantity of the syrup is : " << quantity << endl;
        cout << "The dosage of the syrup : " << dosage << endl;
    }
};
int main()
{
    Tablet T1;
    T1.input();
    cout << "\n";
    syrup S1;
    S1.input();
    T1.output();
    S1.output();
    return 0;
}