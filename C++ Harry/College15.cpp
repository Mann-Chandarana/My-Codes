#include <iostream>
#include <iomanip>
using namespace std;

class Currency
{
private:
    int Rupees;
    int Paisa;
    float amt;

public:
    void enter(void)
    {
        cout << "Enter the amount in terms of rupees" << endl;
        cin >> Rupees;
        cout << "Enter the amount in terms of paisa" << endl;
        cin >> Paisa;
    }

    void show(void)
    {
        if (Paisa > 100)
        {
            Rupees = Rupees + Paisa / 100;
            Paisa = Paisa % 100;
        }
        amt = (float)Rupees + (float)Paisa / 100;
        cout << "Amount :" << setprecision(4) << amt << endl;
    }
    Currency sum(Currency obj)
    {
        Currency a;
        a.Rupees = Rupees + obj.Rupees;
        a.Paisa = Paisa + obj.Paisa;
        return a;
    }

    void add(Currency o1, Currency o2)
    {
        Currency o3;
        o3.Rupees = o1.Rupees + o2.Rupees;
        o3.Paisa = o1.Paisa + o2.Paisa;
    }
};
int main()
{
    Currency M;
    M.enter();
    M.show();

    Currency P;
    P.enter();
    P.show();

    Currency N;
    N = M.sum(P);
    //N.add(M, P);
    N.show();

    return 0;
}