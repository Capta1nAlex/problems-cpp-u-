// Corruption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n, p, tempInput; // N is amount of accounts, P is a fee for merging. 
	cin >> n >> p;
	p = 100 - p; // Value-(Value*p/100) is the same as Value*(100-p)/100, but second variant is a little bit easier to read
	multiset<long long> c; 
	for (int i = 0; i < n; i++) {
		cin >> tempInput;
		c.insert(tempInput * 100); // In this task we don't round money that is less than 0.01 UAH, because of it I'm keeping values in int till the end, not in double
	}
	int newElement;    
	multiset<long long>::iterator ptr1;
	ptr1 = c.begin();
	for (int i = n; n > 1; n--) {
		newElement = (*next(c.begin(), 0) + *next(c.begin(), 1)) * p / 100; 
		c.insert(newElement); // Inserting a new merged account into a set
		ptr1+=2; 
		c.erase(c.begin(), ptr1); // we use iterator in order to clear previous 2 bank accounts
	}
	double result = double(newElement) / 100; // final value is double, because we should show amount of coins on balance, for example "4150.50"
	cout << result << endl;
}
