// luckyTicket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{ 
	int n;
	cin >> n;
	int luckycount = 0;
	for (int i = 0; i < 1000; i++) {
		if (i / 100 + i / 10 % 10 + i % 10 == n) {
			luckycount++;
		}
	}
	cout << pow(luckycount, 2);
}
