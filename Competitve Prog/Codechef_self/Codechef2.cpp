#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int notes[] = {1, 2, 5, 10, 50, 100};

    while (n--)
    {
        int count = 0;
        int currency;
        cin >> currency;
        int i = 5;
        while (currency > 0)
        {
            if (currency >= notes[i])
            {
                currency = currency - notes[i];
                count++;
            }
            else
            {
                i--;
            }
        }
        cout << count << endl;
    }

    return 0;
}