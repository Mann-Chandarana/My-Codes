#include <iostream>
using namespace std;

string Chewbacca_number(string number, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (number[i] > '4')
        {
            number[i] = '9' - number[i] + '0';
        }
    }
    if (number.front() == '0')
    {
        number.front() = '9';
    }

    return number;
}

int main()
{
    string no;
    cin >> no;

    cout << Chewbacca_number(no, no.length()) << endl;

    return 0;
}