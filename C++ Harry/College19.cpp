#include <iostream>
using namespace std;

class Dates
{
    int dd, mm, yyyy;

public:
    void input(void)
    {
        cout << "Enter date" << endl;
        cin >> dd;
        cout << "Enter month" << endl;
        cin >> mm;
        cout << "Enter year" << endl;
        cin >> yyyy;
    }
    void output(void)
    {
        cout << "Entered date is :" << dd << "/" << mm << "/" << yyyy << endl;
    }
    friend void swapp(Dates &, Dates &);
};
void swapp(Dates &a, Dates &b)
{
    int temp = a.dd;
    a.dd = b.dd;
    b.dd = temp;

    int tempe = a.mm;
    a.mm = b.mm;
    b.mm = tempe;

    int tempee = a.yyyy;
    a.yyyy = b.yyyy;
    b.yyyy = tempee;
}
int main()
{
    Dates m;
    m.input();
    m.output();

    cout << "\n";

    Dates p;
    p.input();
    p.output();

    cout << "\n";
    swapp(m, p);

    m.output();
    p.output();

    return 0;
}