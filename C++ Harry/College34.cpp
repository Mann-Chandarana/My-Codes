#include <iostream>
using namespace std;
# define Pi 3.14
class Shape
{
    string Shape_name;

public:
    void input(void)
    {
        cout << "Enter shape name :\n";
        cin >> Shape_name;
    }

    void print(void)
    {
        cout << "Your shape name is : " << Shape_name << endl;
    }
};

class Circle:public Shape
{

public:
    int radius;
    void getData(void)
    {
        cout << "Enter radius :\n";
        cin >> radius;
    }

    void putData(void)
    {
        cout << "Radius entered is : " << radius << endl;
    }
};

class Area:public Circle
{
    int area_of_circle;
    public:
    void display(void)
    {
        input();
        getData();
        print();
        putData();
        area_of_circle = Pi*radius*radius;
        cout<<"The area of the circle : "<<area_of_circle<<endl;
    }

};
int main()
{
    Area obj;
    obj.display();
    return 0;
}