#include <iostream>
#include <string>
using namespace std;
class shop
{
    int itemid[100];
    int itemprice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void getprice(void);
    void displayprice(void);
};
void shop::getprice(void)
{
    cout << "Enter Id of your item no" << counter + 1 << endl;
    cin >> itemid[counter];
    cout << "Enter your price of your item" << endl;
    cin >> itemprice[counter];
    counter++;
}
void shop::displayprice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with with Id " << itemid[i] << " is " << itemprice[i] << endl;
    }
}

int main()
{
    shop dukaan;
    dukaan.initCounter();
    dukaan.getprice();
    dukaan.getprice();
    dukaan.getprice();
    dukaan.displayprice();
    return 0;
}
