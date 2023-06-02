// Corruption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n, p, temp;
	cin >> n >> p;
	p = 100 - p;
	multiset<long long> c;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		c.insert(temp * 100);		
	}
	int newElement;    
	multiset<long long>::iterator ptr1;
	ptr1 = c.begin();
	for (int i = n; n > 1; n--) {
		newElement = (*next(c.begin(), 0) + *next(c.begin(), 1)) * p / 100;
		c.insert(newElement);
		ptr1++;
		ptr1++;
		c.erase(c.begin(), ptr1);
	}
	double result = double(newElement) / 100;
	cout << result << endl;
}