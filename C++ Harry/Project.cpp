#include <iostream>
using namespace std;
//////////////////////////////////////////////////
class Shape
{
    // Created by Mann chandarana
    // Roll no - 20CS011

public:
    double x;
    double y;
    void get_data(double l, double b)
    {
        x = l;
        y = b;
    }
    virtual void display(void)
    {
    }
};
//////////////////////////////////////////////////
class triangle : public Shape
{

public:
    void display(void)
    {
        cout << "Base is " << x << "\nHeigth is " << y << endl;
        cout << "Area of triangle is : " << (x * y)/2 << endl;
    }
};
//////////////////////////////////////////////////
class rectangle : public Shape
{

public:
    void display(void)
    {
        cout << "Length of one side is " << x << "\nLength of other side is " << y << endl;
        cout << "Area of rectangle is : " << x * y << endl;
    }
};

int main()
{
    double val, val1;
    cout << "Enter two side for calculating the area" << endl;
    cin >> val >> val1;
    Shape *ptr;
    rectangle obj;
    triangle obj1;
    obj.get_data(val, val1);
    ptr = &obj;
    ptr->display();
    cout << "\n";

    obj1.get_data(val, val1);
    ptr = &obj1;
    ptr->display();
    return 0;
}