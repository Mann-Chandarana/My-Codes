#include <iostream>
using namespace std;

class Tiles;
class LAND
{

    int length, width, area1;

public:
    void input(void)
    {
        cout << "Enter the length of the land :" << endl;
        cin >> length;
        cout << "Enter the width of the land :" << endl;
        cin >> width;
        area1 = length * width;
    }
    void display(void)
    {
        cout << "The length of the land is : " << length<<endl;
        cout << "The width of the land is : " << width<<endl;
        cout << "The area of the land is : " << area1<<endl;
    }
    friend void No_of_Tiles(LAND, Tiles);
};

class Tiles
{
    int length, width, area2;

public:
    void input(void)
    {
        cout << "Enter the length of the Tiles :" << endl;
        cin >> length;
        cout << "Enter the width of the Tiles :" << endl;
        cin >> width;
        area2 = length * width;
    }
    void display(void)
    {
        cout << "The length of the Tiles is : " << length<<endl;
        cout << "The width of the Tiles is : " << width<<endl;
        cout << "The area of the Tiles is : " << area2<<endl;
    }
    friend void No_of_Tiles(LAND, Tiles);
};
void No_of_Tiles(LAND o1, Tiles o2)
{
    int no_of_tiles;
    no_of_tiles = (o1.area1) / (o2.area2);
    cout << "No of tiles that can be put over the land are : " << no_of_tiles << endl;
}
int main()
{
    LAND GreenVally;
    GreenVally.input();
    GreenVally.display();

    cout << "\n";

    Tiles White;
    White.input();
    White.display();

    cout << "\n";

    No_of_Tiles(GreenVally, White);
    return 0;
}