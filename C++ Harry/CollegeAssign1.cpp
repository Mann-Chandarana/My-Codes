#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

// Name - Mann Chandarana
// Roll no - 20CS011
///////////////////////////////////////////////////////////
class time_12
{
    int HH, MM;
    string time;

public:
    void setTime(int h, int m, string ti)
    {
        HH = h;
        MM = m;
        time = ti;
    }
    int getHour()
    {
        return HH;
    }
    int getMinute()
    {
        return MM;
    }
    string getTimePhase()
    {
        return time;
    }

    void showTime()
    {
        cout << "Time in 12 Hour = " << setfill('0') << setw(2) << HH << ":" << MM << " " << time << endl;
    }
};
///////////////////////////////////////////////////////////
class time_24
{
    int HH, MM;

public:
    time_24() {}

    void setTime(int h, int m)
    {
        HH = h;
        MM = m;
    }

    time_24(time_12 obj) // Class to class typecasting using constructor.
    {
        HH = obj.getHour();
        MM = obj.getMinute();
        string ti = obj.getTimePhase();
        if (HH <= 12 && MM <= 59)
        {
            if ((ti == "PM") && (HH != 0) && (HH != 12))
            {
                HH = HH + 12;
            }
            if ((ti == "AM") && (HH == 12))
            {
                HH = 00;
            }
        }
    }

    operator time_12() // Class to class typecasting using operator keyword.
    {
        time_12 tempTime;
        int h, m;
        string ti;

        if ((HH > 12) && (MM <= 59))
        {
            HH = HH - 12;
            ti = "PM";
        }
        else if (HH == 12)
        {
            ti = "PM";
        }
        else if ((HH < 12) && (MM <= 59))
        {
            ti = "AM";
        }
        else if (HH == 0)
        {
            ti = "AM";
        }

        tempTime.setTime(HH, MM, ti);

        return tempTime;
    }

    void showTime()
    {
        cout << "Time in 24HRS = " << setfill('0') << setw(2) << HH << ":" << MM << endl;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    int n;
    cout << "Enter 0 for 12 hour time format and enter 1 for 24 hour time format : ";
    cin >> n;

    if (n == 0)
    {
        int H, M;
        string ti;
        cout << "Enter time in HH MM AM/PM using space: ";
        cin >> H >> M >> ti;

        time_12 timeIn12Hour;
        time_24 timeIn24Hour;

        timeIn12Hour.setTime(H, M, ti);

        timeIn24Hour = timeIn12Hour; // Typecasting between timeIn24Hour class and timeIn12Hour class using constructor.
        timeIn24Hour.showTime();
    }

    else if (n == 1)
    {
        int H, M;
        cout << "Enter time in HH MM using space: ";
        cin >> H >> M;

        time_24 timeIn24Hour;
        timeIn24Hour.setTime(H, M);

        time_12 timeIn12Hour;
        timeIn12Hour = timeIn24Hour; // Typecasting between timeIn12Hour class and timeIn24Hour class using operator.
        timeIn12Hour.showTime();
    }

    return 0;
}