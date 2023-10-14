#include <iostream>
using namespace std;

class Media
{
public:
    string title;
    float price;

    Media(string t, float p)
    {
        title = t;
        price = p;
    }
    virtual void display(void){};
};

class book : public Media
{
    int page_count;

public:
    book(int p, string title, float price) : Media(title, price)
    {
        page_count = p;
    }
    void display(void)
    {
        cout << "The title is" << title << endl;
        cout << "The price is" << price << endl;
        cout << "page count is" << page_count << endl;
    }
};

class tape : public Media
{
    float playing_with_time;

public:
    tape(float p, string title, float price) : Media(title, price)
    {
        playing_with_time = p;
    }
    void display(void)
    {
        cout << "The title is" << title << endl;
        cout << "The price is" << price << endl;
        cout << "Playing with time in minutes is " << playing_with_time << endl;
    }
};
int main()
{
    Media *MP;
    string Mann;
    tape tp(345, Mann, 383.6);
    MP = &tp;
    tp.display();
    MP->display();

    return 0;
}