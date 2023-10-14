#include <iostream>
#include <vector>
using namespace std;

class HotelRoom
{
    int bedrooms, bathrooms;

public:
    HotelRoom(){};
    HotelRoom(int b, int c)
    {
        bedrooms = b;
        bathrooms = c;
    }
    virtual int getprice(void)
    {
        return (50 * bedrooms) + (100 * bathrooms);
    }
};

class HotelAPartment : public HotelRoom
{
public:
    HotelAPartment(int b, int c):HotelRoom(b,c)
    {
    }

    int getprice(void)
    {
        return HotelRoom::getprice() + 100;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<HotelRoom *> rooms;
    for (int i = 0; i < n; i++)
    {
        string rooms_type;
        int bedrooms;
        int bathrooms;
        cin >> rooms_type >> bedrooms >> bathrooms;
        if (rooms_type == "standard")
        {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        }
        else
        {
            rooms.push_back(new HotelAPartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto element : rooms)
    {
        total_profit += element->getprice();
    }

    cout << total_profit << endl;

    for (auto element : rooms)
    {
        delete element;
    }

    return 0;
}