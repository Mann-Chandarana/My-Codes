#include <iostream>
using namespace std;

class Vegetable
{
    string color;

public:
    void getdata(void)
    {
        cout << "Enter color :" << endl;
        cin >> color;
    }

    void putdata(void)
    {
        cout << "Your color is " << color;
    }
};

class Tomato : public Vegetable
{
    int weight, size;

public:
    void gtdata(void)
    {
        cout << "Enter weigth and size :" << endl;
        cin >> weight >> size;
    }

    void ptdata(void)
    {
        cout << "Weight is :" << weight << endl;
        cout << "Size is :" << size << endl;
        putdata();
    }
};
int main()
{
    Tomato obj;
    obj.getdata();
    obj.gtdata();
    obj.ptdata();
    return 0;
}