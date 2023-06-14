// luckyTicket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{ 
	int n; // sum of the three digits of lucky tickets
	cin >> n;
	int luckycount = 0; // amount of combinations on 1 side
	for (int i = 0; i < 1000; i++) { // ticket numbers are [000,001...,999]
		if (i / 100 + i / 10 % 10 + i % 10 == n) {
			luckycount++;
		}
	}
	cout << pow(luckycount, 2); 
}
