#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    // ofstream out;
    // out.open("Sample60.txt");
    // out << "This is me\n";
    // out << "This is me also\n";
    // out << "This is also\n";
    // out << "This is also me\n";
    // out.close();

    ifstream in;
    string st, st2;
    in.open("Sample60b.txt");
    //in>>st>>st2;
    //cout << st << st2;
    while (in.eof() == 0)
    {
        getline(in, st);
        cout << st << endl;
    }

    return 0;
}