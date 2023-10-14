#include <iostream>
using namespace std;

class Daytype
{
    // Created by Mann chandarana
    // Roll no - 20CS011
    string Days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string current_Day;
    int num;

public:
    void getDay(int in)
    {
        num = in;
        current_Day = Days[num];
    }
    /////////////////////////////////////////////////////
    void printDay(void)
    {
        cout << "Your day is " << current_Day << endl;
    }
    /////////////////////////////////////////////////////
    void nextDay(void)
    {
        int index = num;
        index = index + 1;
        if (index >=6)
        {
            index = index % 7;
            if (index == 0)
            {
                index + 1;
            }
        }
        cout << "Next day is " << Days[index] << endl;
    }
    /////////////////////////////////////////////////////
    void previousDay(void)
    {
        int index1 = num;
        index1 = index1 - 1;
        if (index1 < 0)
        {
            index1 = index1 + 7;
        }
        cout << "Previous Day is " << Days[index1] << endl;
    }
    /////////////////////////////////////////////////////
    void AddDays(int x)
    {
        int index3 = num;
        index3 = index3 + x;
        if (index3 > 7)
        {
            index3 = index3 % 7;
        }
        cout << "Day after adding " << x << " is " << Days[index3] << endl;
    }
};
//////////////////////////////////////////////////////////
int main()
{
    int in, x;
     cout << "****************************************************************" << endl;
    cout << "Enter index\n 0-for Monday\n 1-for Tuesday\n 2-for Wednesday\n 3-for Thursday\n 4-for friday\n 5-for Saturday\n 6-for Sunday\n";
    cin >> in;
    cout << "Day after adding digit" << endl;
    cin >> x;
    Daytype D1;
    D1.getDay(in);
    D1.printDay();
    D1.nextDay();
    D1.previousDay();
    D1.AddDays(x);
     cout << "****************************************************************" << endl;

    return 0;
}