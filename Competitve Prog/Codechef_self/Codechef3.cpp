#include <iostream>
using namespace std;


int main() {
	size_t no_tests ;
	cin >> no_tests ;
	
	for (size_t i = 0 ; i < no_tests ; i++) {
	    size_t a, b ;
	    cin >> a >> b ;
	    
	    size_t gcd, lcm = a*b ;
	    
        if (a==0) {
            gcd = b ;
        } else {
            while (b!=0) {
                if (a>b) {
                    a -= b ;
                } else {
                    b -= a ;
                }
            }
            gcd = a ;
        }
	    lcm /= gcd ;
	    
	    cout << gcd << " " << lcm << endl ;
	}
	
	return 0;
}
