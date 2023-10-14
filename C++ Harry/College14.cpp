#include <iostream>
#include <string.h>
using namespace std;

class Batsman
{
private:
    char name[50];
    int bcode, innings, not_out, runs;
    float batting_average;
    int calavg();

public:
    void getdata();
    void printdata();
};

void Batsman::getdata(void)
{
    cout << "Enter batsman name :" << endl;
    cin.getline(name, 50);
    cout << "Enter batsman code :" << endl;
    cin >> bcode;
    cout << "Enter batsman innings :" << endl;
    cin >> innings;
    cout << "Enter batsman not out inningss :" << endl;
    cin >> not_out;
    cout << "Enter batsman runs :" << endl;
    cin >> runs;
}

int Batsman::calavg(void)
{
    int average = runs / (innings - not_out);
    return average;
}

void Batsman::printdata(void)
{
    cout << "\nBatsman name is " << name << endl;
    cout << "Batsman code is " << bcode << endl;
    cout << "Batsman innings are " << innings << endl;
    cout << "Batsman not out innings are " << not_out << endl;
    cout << "Batsman runs are " << runs << endl;
    cout << "Batsman average is " << calavg() << endl;
}
int main()
{
    Batsman ViratK;
    ViratK.getdata();
    ViratK.printdata();
    return 0;
}