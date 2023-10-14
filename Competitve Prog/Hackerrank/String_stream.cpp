#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> parserInts(string s) //Function which return vector
{
    vector<int> v1;
    stringstream ss(s);
    int a;
    char ch;
    while (ss >> a) // a will extract int from ss
    {
        v1.push_back(a);
        ss >> ch; // ch will extract char from ss
    }
    return v1;
}

int main()
{
    string str;
    cin >> str;
    vector<int> v2;
    v2 = parserInts(str);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }

    return 0;
}
