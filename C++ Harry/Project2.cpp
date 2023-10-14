#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
// Created by - Mann Chandarana
// Roll no - 20CS011
class swimmingpool
{
    float l, w, d, filling_rate, draining_rate;

public:
    swimmingpool()
    {
        cout << "Enter Length,width,depth of the pool in feet:";
        cin >> l >> w >> d;
        cout << "Enter the rate at which water is filling the pool(gallons/min):";
        cin >> filling_rate;
        cout << "Enter the rate at which water is draining the pool(gallons/min):";
        cin >> draining_rate;
    }
    void water_amount()
    {
        int choice;
        cout << "\n\nRequired amount of the water to fill the pool." << endl;
        cout << "Enter 1 for empty pool.Enter 2 for partially filled pool:";
        cin >> choice;
        float vol = l * w * d;
        if (choice == 1)
        {
            cout << "Amount of water required:" << vol << "cubicfeet.(" << 7.481 * vol << "gallons)" << endl;
        }
        else if (choice == 2)
        {
            float vol1;
            cout << "Enter volume already filled in cubic feet:";
            cin >> vol1;
            float nvol = vol - vol1;
            cout << "Amount of water required: " << nvol << " cubic feet.(" << 7.481 * nvol << "gallons)" << endl;
        }
        else
        {
            cout << "Enter appropriate value. " << endl;
        }
    }
    void required_time()
    {
        int choice;
        cout << "\n\nTime required to fill the pool with water." << endl;
        cout << "Enter 1 for empty pool.Enter 2 for partially filled pool.:";
        cin >> choice;
        float vol = l * w * d;

        if (choice == 1)
        {
            int time = (7.481 * vol / (filling_rate - draining_rate));
            if (time > 0)
            {
                cout << "Time required:" << time << "min" << endl;
            }
            else
            {
                cout << "Draining rate is greater than filling rate so water cannot be filled" << endl;
            }
        }
        else if (choice == 2)
        {
            float vol1;
            cout << "Enter volume already filled in cubic feet:";
            cin >> vol1;
            float nvol = vol - vol1;
            int time = (filling_rate - draining_rate);
            if (time > 0)
            {
                cout << "Time required:" << (7.481 * nvol / (filling_rate - draining_rate)) << "min" << endl;
            }
            else
            {
                cout << "Draining rate is greater than filling rate so water cannot be filled" << endl;
            }
        }
        else
            cout << "Enter appropriate value" << endl;
    }
    void specific_time()
    {
        float vol;
        int time, filledVolume;
        vol = l * w * d;
        cout << "\n\nAdd or drain water rate at specific time" << endl;
        cout << "Enter a specfic time(in min):";
        cin >> time;
        filledVolume = (time / filling_rate);
        cout << "Amount of water added in a particular time is " << vol + filledVolume << endl;
        filledVolume = (time / draining_rate);
        cout << "Amount of water drained in a particular time is " << vol - filledVolume << endl;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    swimmingpool p;
    p.water_amount();
    p.required_time();
    p.specific_time();
    return 0;
}