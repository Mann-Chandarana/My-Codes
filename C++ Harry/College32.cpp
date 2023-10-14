#include <iostream>
using namespace std;

class alpha
{
    int x;

public:
    alpha(){};
    alpha(int x)
    {
        this->x = x;
    }
    void display(void)
    {
        cout << x << endl;
    }
};

class Beta
{
    float y;

public:
    Beta(){};
    Beta(float y)
    {
        this->y = y;
    }
    void display(void)
    {
        cout << y << endl;
    }
};

class Gamma : public alpha, public Beta
{
    int m, n;

public:
    Gamma(int x, float y, int m, int n) : alpha(x), Beta(y)
    {
        this->m = m;
        this->n = n;
    }

    void print(void)
    {
        cout << m << endl
             << n;
        alpha::display();
        Beta::display();
    }
};
int main()
{
    Gamma obj(55,53.25,56,58);
    obj.print();
    return 0;
}