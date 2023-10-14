#include <iostream>
#include <math.h>
using namespace std;

void isArmstrong_no(string number, int len)
{
    int multiplier = len;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += pow(int(number[i] - '0'), multiplier);
    }
    if (sum == stoi(number))
    {
        cout << sum << endl;
    }
}

int main()
{
    int N1, N2;
    cin >> N1 >> N2;

    for (int i = N1; i <= N2; i++)
    {
        string value = to_string(i);
        isArmstrong_no(value, value.length());
    }

    return 0;
}