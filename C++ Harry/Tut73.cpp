#include <iostream>
#include <map>
#include <string>
// It is similar to dici in python
using namespace std;

// Map is an associative array
int main()
{
    map<string, int> marksmap;
    marksmap["Mann"] = 98;
    marksmap["Parth"] = 59;
    marksmap["Niraj"] = 2;
    marksmap.insert({{"Aditya", 15}, {"Hithik", 10}});
    map<string, int>::iterator iter;
    for (iter = marksmap.begin(); iter != marksmap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << "\n";
    }
    cout << "The size is: " << marksmap.size() << endl;
    cout << "The max_size is: " << marksmap.max_size() << endl;
    cout << "The empty's return value is : " << marksmap.empty() << endl;

    return 0;
}