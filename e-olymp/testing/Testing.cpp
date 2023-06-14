// Testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int gcd(long long vl, long long v2) // finding greatest common divider
{
	while (v2)
	{
		long long temp = v2;
		v2 = vl % v2;
		vl = temp;
	}
	return abs(vl);
}
int main()
{
	long long nom1, denom1, nom2, denom2, nomR, denomR;
	cin >> nom1 >> denom1 >> nom2 >> denom2;
	nomR = nom1 * denom2 + denom1 * nom2; // getting nominator of final result
	denomR = denom1 * denom2; // getting denominator of final result
	long long recall = nomR; 
	nomR = nomR / gcd(nomR, denomR);  // simplifying a fraction 
	denomR = denomR / gcd(recall, denomR); // simplifying a fraction 
	cout << nomR << " ";
	cout << denomR << " ";
}
