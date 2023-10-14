#include <iostream>

using namespace std;

int main()
{
    int *p = nullptr;
    // cout << *p << endl; // Will terminate the program with segmentation fault.
    // cout << "test" << endl;
    int n = 67;
    p = &n;
    cout << *p << endl;
    
    // Copying a pointer
    int *q = p;
    cout << q << " - " << p << endl;
    cout << *q << " - " << *p << endl;
    
    // q = q + 1, will move q by 4 bytes (size of integer);
    cout << q << endl;
    q++;
    cout << q << endl;
    
    

    return 0;
}
