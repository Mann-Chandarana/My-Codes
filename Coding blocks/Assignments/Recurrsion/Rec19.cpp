//////////// Move all x to end

#include <iostream>
using namespace std;

void moveAllX(char *inp, int i)
{
    if (inp[i] == '\0' && inp[i + 1] == '\0')
    {
        return;
    }
    if (inp[i] == 'x')
    {
        int ele = inp[i];
        int j = i;
        while (inp[j + 1] != '\0')
        {
            inp[j] = inp[j + 1];
            j++;
        }
        inp[j] = ele;
        moveAllX(inp, i + 1);
    }
    else
    {
        moveAllX(inp, i + 1);
    }
}

int main()
{
    char inp[100];
    cin >> inp;

    moveAllX(inp, 0);
    cout << inp << endl;

    return 0;
}