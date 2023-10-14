#include <iostream>
using namespace std;

template <class T>
class Mann
{
public:
    T data;
    Mann(T a)
    {
        data = a;
    }
    void display();
};

template<class T>
void Mann<T>::display()
{
    cout<<data;
}
//
void func(int a)
{
    cout<<"I am first func()"<<endl;
}
//
template <class T>
void func(T a)
{
    cout<<"I am Templatised func()"<<endl;
}
template <class T>
void func1(T a)
{
    cout<<"I am Templatised func()"<<endl;
}
int main()
{
    // Mann<int> m(5);
    // cout << m.data;
    // m.display();

    func(4);// Exact match takes the highest priority
    func1(4);
    return 0;
}