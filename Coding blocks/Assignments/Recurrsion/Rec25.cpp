///////////////////// Replace PI

#include <iostream>
using namespace std;

void replace_Pi(char *inp, int i)
{
    if (inp[i] == '\0' || inp[i + 1] == '\0')
    {
        return;
    }
    if (inp[i] == 'p' && inp[i + 1] == 'i')
    {
        int j = i + 2;
        while (inp[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            inp[j + 2] = inp[j];
            j--;
        }
        inp[i] = '3';
        inp[i + 1] = '.';
        inp[i + 2] = '1';
        inp[i + 3] = '4';

        replace_Pi(inp, i + 4);
    }
    else
    {
        replace_Pi(inp, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    char inp[100];

    while (n--)
    {
        cin >> inp;
        replace_Pi(inp, 0);
        cout << inp << endl;
    }

    return 0;
}