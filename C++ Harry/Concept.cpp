#include <iostream>
using namespace std;

int main()
{
    char *s;
    s = new char[30];
    cin.get(s,30);
    cout << s;

    return 0;
}