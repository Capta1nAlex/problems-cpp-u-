// WithoutLift.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;
int main()
{
	multiset<int>s;
	int temp;
	cin >> temp;
	s.insert(temp);
	cin >> temp;
	s.insert(temp);
	cin >> temp;
	s.insert(temp);
	double a, b, c;
	a = *next(s.begin(), 0);
	b = *next(s.begin(), 1);
	c = *next(s.begin(), 2);
	if ((b - a) * 47 / 31 > (c - a)) {
		cout << a;
	}
	else cout << b;
}