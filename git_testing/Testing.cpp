// Testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int gcd(long long vl, long long v2)
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
	long long a, b, v, w, cin1, cin2;
	cin >> a;
	cin >> b;
	cin >> v;
	cin >> w;
	cin1 = a * w + b * v;
	cin2 = b * w;
	long long recall = cin1;
	cin1 = cin1 / gcd(cin1, cin2);
	cin2 = cin2 / gcd(recall, cin2);
	cout << cin1 << " ";
	cout << cin2 << " ";
}