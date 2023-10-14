#include <iostream>
#include <climits>
using namespace std;

// Double pointers

void update(int **a)
{
    /*
        // (**a)++;
        // cout << **a << endl;
        // // It will change a in the main() function.
        
        // (*a)++;
        // cout << "Inside: " << *a << endl; 
        // It will change the value (the block initial pointer is pointing) for both update() and main() function.
        
        // a++;
        // cout << "Inside: " << a << endl;
        // // This will change the value in p1 for the update() function, but not for the main() function.
    */
    
    /*
        a = a + 1;
        Kuch change hoga? NO.
        
        *a = *a + 1;
        Kuch change hoga? YES, *a (*p2 in main function) will change the value of p1.
        
        **a = **a + 1;
        Kuch change hoga? YES, a of the main() function, will be increamented.
    */
    
    /*
        // a = a + 1; // Nothing will change
        // *a = *a + 1; // value of p1 is changed in the main(), p1 is not pointing to a anymore.
        // **a = **a + 1; // Value of a is cahnge in th main().
    */
}

int main()
{
    int a = 5; // int
    int *p1 = &a; // p1 is a pointer pointing to a int variable.
    int **p2 = &p1; // p2 is a pointer pointing to a int pointer.
    
    /*
        // cout << "a -> " << a << endl;
        // cout << "*p1 -> " << *p1 << endl;
        // cout << "**p2 -> " << **p2 << endl;
        // cout << endl;
        // cout << "*p2 -> " << *p2 << endl;
        // cout << "p1 -> " << p1 << endl;
        // cout << "&a -> " << &a << endl;
        // cout << endl;
        // cout << "p2 -> " << p2 << endl;
        // cout << "&p1 -> " << &p1 << endl;
        // cout << endl;
        // cout << "&p2 -> " << &p2 << endl;
    */
    
    /*
    // // cout << "Before: " << p2 << endl;
    // cout << "Before the update function, p1: " << p1 << endl;
    // cout << "Before the update function, *p1: " << *p1 << endl;
    // update(p2);
    // cout << "After the update function, p1: " << p1 << endl; // p1 has an updated value from the update() function.
    // cout << "After the update function, *p1: " << *p1 << endl;
    // // cout << "After: " << p2 << endl;
    */
    
    /*
        cout << "Before: " << a << endl;
        cout << "Before: " << p1 << endl;
        cout << "Before: " << p2 << endl;
        update(p2);
        // Try this for a = a + 1, *a = *a + 1, **a = **a + 1 in the update function.
        cout << "After: " << a << endl;
        cout << "After: " << p1 << endl;
        cout << "After: " << p2 << endl;
    */
    
    return 0;
}
