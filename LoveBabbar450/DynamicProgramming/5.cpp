/* Catalan Number :- Number of unique binary search tree */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/*
C0 - 1
C1 - 1
C2 - C0*C1 + C1*C0
C3 - C0*C2 + C1*C1 + C2*C0
C4 - C0*C3 + C1*C2 + C2*C1 + C3*C0
*/

/* Solution-1) A recursive function to find nth catalan number */

unsigned long int catalan(unsigned int n) 
{ 
	// Base case 
	if (n <= 1) return 1; 

	// catalan(n) is sum of catalan(i)*catalan(n-i-1) 
	unsigned long int res = 0; 
	for (int i=0; i<n; i++) 
		res += catalan(i)*catalan(n-i-1); 

	return res; 
} 

/* Soution-2) A dynamic programming based function to find nth */

unsigned long int catalanDP(unsigned int n) 
{ 
	// Table to store results of subproblems 
	unsigned long int catalan[n+1]; 

	// Initialize first two values in table 
	catalan[0] = catalan[1] = 1; 

	// Fill entries in catalan[] using recursive formula 
	for (int i=2; i<=n; i++) 
	{ 
		catalan[i] = 0; 
		for (int j=0; j<i; j++) 
			catalan[i] += catalan[j] * catalan[i-j-1]; 
	} 

	// Return last entry 
	return catalan[n]; 
} 


/* Solution-3) Returns value of Binomial Coefficient C(n, k) */

unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 
// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 


int main()
{
    return 0;
}