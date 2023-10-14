#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

// void update(int *pr, int *qr)
// {
//     int var = *pr;
//     *pr = *pr + *qr;
//     *qr = var - *qr;
//     if (*qr < 0)
//     {
//         *qr = -(*qr);
//     }
// }
// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     int *p = &a;
//     int *q = &b;

//     update(p, q);
//     cout << a << endl;
//     cout << b << endl;
//     return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////
class Student
{
    int age, standard;
    string first_name, last_name;

public:
    void setage(int a)
    {
        age = a;
    }
    void set_standard(int a)
    {
        standard = a;
    }
    void set_age(int a)
    {
        age = a;
    }
    void set_first_name(string l)
    {
        first_name = l;
    }
    void set_last_name(string m)
    {
        last_name = m;
    }

    int get_age(void)
    {
        return age;
    }
    string get_last_name(void)
    {
        return last_name;
    }
    string get_first_name(void)
    {
        return first_name;
    }
    int get_standard(void)
    {
        return standard;
    }
    void to_string(void)
    {
        cout << age << "," << first_name << "," << last_name << "," << standard;
    }
};
int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();

    return 0;
}