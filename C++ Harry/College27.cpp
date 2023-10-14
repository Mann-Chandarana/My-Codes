#include <iostream>
using namespace std;
template <class T>
class Measure
{
    T meter, cm;

public:
    void get(T m, T c)
    {
        meter = m;
        cm = c;
    }

    void put(void)
    {
        cout << "You entered " << meter << " and " << cm << endl;
    }

    Measure operator+(T b)
    {
        Measure temp;
        temp.meter = meter + b;
        temp.cm = cm + b;
        return temp;
    }

    Measure operator-(T c)
    {
        Measure tempe;
        tempe.meter = meter - c;
        tempe.cm = cm - c;
        return tempe;
    }
};
int main()
{
    Measure<int> M1, M2;
    M1.get(10, 15);
    M1.put();
    M2 = M1 + 15;
    M2.put();

    Measure<float> M3, M4;
    M4.get(15.5, 20.6);
    M4.put();
    M3 = M4-4.5;
    M3.put();
    return 0;
}