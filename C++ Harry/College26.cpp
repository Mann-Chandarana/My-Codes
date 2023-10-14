#include <iostream>
#include <string.h>
using namespace std;

class String
{
    char arr[30];

public:
    String(){};

    String(char a[10])
    {
        cout << "\nParameterized !" << endl;
    }
    ///////////////////////////////////////////////////
    void get(void)
    {
        cout << "Enter the string :" << endl;
        cin >> arr;
    }
    ///////////////////////////////////////////////////
    void put(void)
    {
        cout << "\nThe entered string is : " << arr << endl;
    }
    ///////////////////////////////////////////////////
    String operator+(String &s)
    {
        String t;
        strcat(arr, s.arr);
        strcpy(t.arr, arr);
        return t;
    }
    ///////////////////////////////////////////////////
    int operator<(String obj)
    {
        int a;
        a = strcmp(arr, obj.arr);
        return a;
    }
    ///////////////////////////////////////////////////
    String operator+=(String obj1)
    {
        String temp;
        strcat(arr, obj1.arr);
        strcpy(temp.arr, arr);
        return temp;
    }
};

int main()
{
    // String s1, s2, s3;
    // s1.get();
    // s2.get();
    // s3 = s1 + s2;
    // s3.put();

    ///////////////////////////////////////////////////

    // String s1, s2;
    // int b;
    // s1.get();
    // s2.get();
    // b = s1 < s2;
    // cout << "Comparing the string the difference is :\n"<< b << endl;

    ///////////////////////////////////////////////////

    String s1, s2;
    s1.get();
    s2.get();
    s1 += s2;
    s1.put();
    return 0;
}