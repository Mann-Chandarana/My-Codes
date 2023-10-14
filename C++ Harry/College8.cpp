//1. //This is an example of constant pointer
#include <iostream>
using namespace std;
int main()
{
    int var1 = 35, var2 = 20;
    int *const ptr = &var1;
    ptr = &var2;
    cout << "var1= " << *ptr;
    return 0;
}

//2. //This is an example of pointer to constant

    int
    main()
{
    int var1 = 43;
    const int *ptr = &var1;
    *ptr = 1;
    var1 = 34;
    cout << "var1 = " << *ptr;
    return 0;
}

//3. //This is an example of constant pointer to a constant

    int
    main()
{
    int var1 = 0, var2 = 0;
    const int *const ptr = &var1;
    *ptr = 1;
    ptr = &var2;
    cout << "Var1 = " << *ptr;
    return 0;
}