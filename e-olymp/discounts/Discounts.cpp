// Discounts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n, temp;
	vector <int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	if (n % 3 != 1) {
		for (int i = n-1; i > 0; i -= 3) {
			sum += vec[i] + vec[i - 1];
		}
	}
	else {
		for (int i = n-1; i > 1; i -= 3) {
			sum += vec[i] + vec[i - 1];
		}
		sum += vec[0];
	}
	cout << sum;
}