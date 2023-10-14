#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> marksmap;
    while (n--)
    {
        int query, marks;
        string name;
        cin >> query;
        if (query == 1)
        {
            cin >> name >> marks;
            marksmap[name] += marks; // it will add name and marks in the map list
        }
        if (query == 2)
        {
            cin >> name;
            marksmap.erase(name); // it will remove key of that object
        }
        if (query == 3)
        {
            cin >> name;
            map<string, int>::iterator itr = marksmap.find(name);
            if (itr != marksmap.end())
            {
                cout << (*itr).second << endl; //marksmap[name]
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}