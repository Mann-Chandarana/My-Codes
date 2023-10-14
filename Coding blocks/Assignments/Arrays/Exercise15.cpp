#include <iostream>
using namespace std;

int main()
{
    char c;
    
    do
    {
        cin >> c;
        int a, b;
        if (c == 'x' or c == 'X')
            break;
        switch (c)
        {
        case '*':
            cin >> a >> b;
            cout << a * b << endl;
            break;
        case '+':
            cin >> a >> b;
            cout << a + b << endl;
            break;
        case '-':
            cin >> a >> b;
            cout << a - b << endl;
            break;
        case '/':
            cin >> a >> b;
            cout << a / b << endl;
            break;
        default:
            cout << "Invalid operation. Try again." << endl;
            break;
        }
    } while ((c != 'X') or (c != 'x'));

    return 0;
}