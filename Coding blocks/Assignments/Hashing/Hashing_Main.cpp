#include <bits/stdc++.h>
#include "Hashing1.h"
using namespace std;

int main()
{
    Hashtable <int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noddles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print();
    cout << "My name is Mann " << price_menu["Burger"] << endl;

    return 0;
}