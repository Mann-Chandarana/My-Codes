// 1) - In constant member function you cannot modify the value of data members
// #include <iostream>
// using namespace std;
// class sample
// {
//     int m, n;

// public:
//     void getdata();
//     void putdata() const;
// };
// void sample::getdata()
// {
//     cout << "Enter m & n" << endl;
//     cin >> m >> n;
// }
// void sample::putdata() const
// {
//     // m = 12;
//     // n = 34;
//     cout << "m = " << m << "\nn= " << n;
// }
// int main()
// {
//     sample s1;
//     s1.getdata();
//     s1.putdata();
//     return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////////

// 2) - Here s is not a pointer it is a object so we cannot use operator (->)  and to acces pointer to data member we have to
//use operator (.*)
// include <iostream>
// using namespace std;
// class student
// {
// public:
//     int roll_no;
// };
// int main()
// {
//     // declaring pointer to data member
//     int student ::*p1 = &student::roll_no;
//     student s;
//     student *optr = &s;
//     optr->roll_no = 42;
//     cout# << "Roll no is " << (*optr).*p1 << endl;
//     (*optr).*p1 = 45;
//     cout << "Roll no is " << (*optr).*p1 << endl;
//     return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////////

/* 3) a) (.*) this operator is used with object of the class to access pointer memeber function or data member
      b)  (->*) this operator is used with pointer of the object of the class to access pointer memeber function or data member*/
// #include <iostream>
// using namespace std;
// class employee
// {
// public:
//     void hello()
//     {
//         cout << "Hi hello" << endl;
//     }
// };
// int main()
// {
//     // declaring pointer to member function hello
//     void (employee ::*fp)() = &employee::hello;
//     employee e;
//     employee *optr = &e;
//     (e.*fp)();
//     (optr->*fp)();
//     return 0;
// }

/////////////////////////////////////////////////////////////////////////////////////////////////

/* 4) - a) We cannot use static member or function outside the class
        b) We cannot define member function outside the class in local class */
#include <iostream>
using namespace std;
void testlocalclass()
{
    class Test
    {
        int cnt;

    public:
        void set()
        {
            cout << "Enter Count: ";
            cin >> cnt;
        }
        void get()
        {
            cout << "Count: = " << cnt;
        }
    };
    Test t;
    t.set();
    t.get();
}
int main()
{
    testlocalclass();
    return 0;
}
