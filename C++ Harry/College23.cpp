#include <iostream>
using namespace std;

class time
{
    int hr, min, sec;

public:
    time()
    {
        cout << "Calling Default constructor " << endl;
    }

    time(int hour, int minute = 52, int second = 52)
    {
        cout << "Calling parameterized constructor with default value " << endl;
        hr = hour;
        min = minute;
        sec = second;
    }

    time(time &obj)
    {
        cout << "Calling our copy constructor !! " << endl;
        hr = obj.hr;
        min = obj.min;
        sec = obj.sec;
    }
    ~time()
    {
        cout << "Calling destructor " << endl;
    }

    void getdata(void)
    {
        cout << "Enter hour :" << endl;
        cin >> hr;
        cout << "Enter minute :" << endl;
        cin >> min;
        cout << "Enter second :" << endl;
        cin >> sec;
    }

    void putdata(void)
    {
        cout << hr << ":" << min << ":" << sec << endl;
    }
};
int main()
{
    time M1;
    M1.getdata();
    M1.putdata();
    cout << "\n";
    time M2(10, 59);
    M2.putdata();
    cout << "\n";
    time M3(M1);
    M3.putdata();
    return 0;
}