#include <iostream>
#include <iomanip>
using namespace std;

float volume(float r1 = 2, float r2 = 3, float r3 = 4)
{
    float volume;
    volume = 1.333 * 3.14 * r1 * r2 * r3;
    return volume;
}
int main()
{
    cout << "********************************" << endl;
    float num1, num2, num3;
    cout << "Enter radius 1 " << endl;
    cin >> num1;
    cout << "Enter radius 2 " << endl;
    cin >> num2;
    cout << "Enter radius 3 " << endl;
    cin >> num3;
    float v;
    cout << "********************************" << endl;
    v = volume(num1, num2, num3);
    cout << "Volume  of Ellipsod is " << v << endl;
    cout << "********************************" << endl;
    v = volume();
    cout << "Volume  of Ellipsod is " << fixed << setprecision(2) << v << endl;

    return 0;
}