#include <iostream>
using namespace std;

class c2;

class c1
{
    int val1;

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display()
    {
        cout << val1 << endl;
    }
    friend void swap(c1 &, c2 &);
};

class c2
{
    int val2;

public:
    void indata(int a)
    {
        val2 = a;
    }
    void display()
    {
        cout << val2 << endl;
    }
    friend void swap(c1 &, c2 &);
};

void swap(c1 &o1, c2 &o2)
{
    int temp = o1.val1;
    o1.val1 = o2.val2;
    o2.val2 = temp;
}
int main()
{
    c1 x;
    c2 y;
    x.indata(10);
    y.indata(15);
    swap(x, y);
    cout << "Value of val1 after swapping : "; 
    x.display();
    cout << "Value of val2 after swapping : ";
    y.display();

    return 0;
}