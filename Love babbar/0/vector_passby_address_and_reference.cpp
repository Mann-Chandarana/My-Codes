#include <iostream>
#include <vector>
using namespace std;

/*
    :: is the scoping operator, . is the access operator, and -> is the dereference arrow
*/

// Passing vector by pointer
void fun1(vector<int> *v)
{
    for(int i=0;i<v->size();i++)
        v->at(i) *= 10;
}

void print1(vector<int> *v)
{
    for(int i=0;i<v->size();i++)
        cout << v->at(i) << " ";
    cout << endl;
}

// Passing vector by reference
void fun2(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
        v[i] *= 10;
}

void print2(vector<int> &v)
{
    for(auto i:v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // Pass by address
    vector<int> v1 = {1,2,3,4,5};
    print1(&v1);
    fun1(&v1);
    print1(&v1);
    
    cout << endl;
    
    // Pass by value
    vector<int> v2 = {1,2,3,4};
    print2(v2);
    fun2(v2);
    print2(v2);
    
    return 0;
}
