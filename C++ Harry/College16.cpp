#include <iostream>
using namespace std;

class Dist
{
public:
    int feet;
    float inches;
    float scale_factor;
    void input()
    {
        cout << "'Enter feet:" << endl;
        cin >> feet;
        cout << "Enter inches:" << endl;
        cin >> inches;
        cout << "Enter scale factor:" << endl;
        cin >> scale_factor;
    }

    void display(void)
    {
        cout << "Scaled Distance :" << feet << "\'-" << inches << "\"";
    }

    void scale(float sf, Dist &ob)
    {
        ob.feet = feet * sf;
        ob.inches = inches * sf;
    }
};
int main()
{
    Dist d;
    Dist d1;
    d.input();
    d.scale(d.scale_factor, d);
    d.display();
    return 0;
}