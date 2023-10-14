#include <iostream>
using namespace std;

int main()
{
    char button;
    cin >> button;
    switch (button)
    {
    case 'a':
        cout << "Hello" << endl;
        break;
    case 'b':
        cout << "Namste" << endl;
        break;
    case 'c':
        cout << "salute" << endl;
        break;
    case 'd':
        cout << "Hola" << endl;
        break;
    case 'e':
        cout << "ciao" << endl;
        break;

    default:
        cout << "I am still learning more" << endl;
        break;
    }
    return 0;
}
