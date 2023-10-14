#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    float arr[5];

    fstream file;
    file.open("Mann.txt", ios::out);
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        file << arr[i] << endl;
    }
    int p = file.tellg();

    file.close();

    fstream file1;
    file1.open("Mann.txt", ios::in);
    float height;
    for (int i = 0; i < 5; i++)
    {
        file1 >> height;
        cout << fixed << setprecision(2) << height << endl;
    }

    return 0;
}