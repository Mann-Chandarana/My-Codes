/*
#include "bits/stdc++.h"

using namespace std;

// gcd(a,b) = gcd(a-b,b); if a > b
// or gcd(a,b) = gcd(a,b-a); if b > a
int gcd(int a, int b)
{
    if(a == 0)
        return b;
    
    if(b == 0)
        return a;
    
    while(a != b)
    {
        if(a == 1 or b == 1)
            return 1;
            
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    
    return a;
}

// IMP
// gcd(a,b) * lcm(a,b) = a*b 

int main()
{
    // cout << LONG_MAX << " " << INT_MAX << " " << LONG_MAX/ INT_MAX << endl;
    // cout << ULONG_MAX << " " << UINT_MAX << " " << ULONG_MAX/ UINT_MAX <<  endl;
    
    int a,b;
    cout << "enter a and b: ";
    cin >> a >> b;
    
    cout << __gcd(a,b) << endl; // __gcd(a, b) is an inbuilt function.
    cout << gcd(a,b) << endl;

    return 0;
}
*/

#include "bits/stdc++.h"

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int res = 1;
    
    while(b > 0)
    {
        if(b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b = b >> 1;
        
    }
    
    cout << res << endl;
    
    return 0;
    
}