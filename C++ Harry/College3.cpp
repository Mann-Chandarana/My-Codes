#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float num1, num2, result;
    cin >> num1 >> num2;
    result = num1 + num2;
    cout << result << " (Without Precision)\n";
    cout <<fixed<<setprecision(3)<<result<<" (With fixed)\n";
    cout << scientific<<setprecision(2)<<result<<" (With scientific)";

    return 0;
}